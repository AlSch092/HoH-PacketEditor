#include "PacketParsing.hpp"

extern bool g_LoggingSendPackets;

std::queue<PacketWriter*> SendPacketQueue;
std::queue<PacketWriter*> RecvPacketQueue;
std::list<ModifyRule*> ModifyList;
std::list<uint16_t> IgnoredList;

int PacketHelper::rand_lim(int limit)
{
	int divisor = RAND_MAX / (limit + 1);
	int retval;

	do {
		retval = rand() / divisor;
	} while (retval > limit);

	return retval;
}


LPBYTE PacketHelper::ToPacketFormat(CHAR* input) //wrote this routine in 2015, not a prime example of 'clean' code but it works just fine
{
	if (input == NULL)
		return NULL;

	int in_len = strlen(input);

	if (strlen(input) > MAX_BUFFER_LENGTH)
		return NULL;

	char* fixedString = new char[in_len + 1];
	LPBYTE bytestring = NULL;

	//strip spaces, bad text
	int i; int j = 0;

	for (i = 0; input[i] != '\0'; i++) 
	{
		if (input[i] == ' ')
			continue;
		else if((input[i] >= 'A' && input[i] <= 'F') || (input[i] >= '0' && input[i] <= '9') || (input[i] >= 'a' && input[i] <= 'f'))
		{
			fixedString[j] = input[i];
			j++;
		}
		else if (input[i] == '*') 
		{
			int random = rand_lim(15);

			if (random >= 0 && random <= 9) 
				fixedString[j] = random + 0x30;			
			else if (random >= 9 && random <= 15) 
				fixedString[j] = random + 0x55;
			
			j++;
		}	
		else //found non-hex digit in string  
		{	
			delete[] fixedString;
			return NULL;
		}
	}

	bytestring = (unsigned char*)malloc((j * 2) + 1);

	j = 0;

	for (i = 0; fixedString[i] != '\0'; i++) 
	{
		if (i % 2 == 0)  //even number iterator
		{
			if (fixedString[i] >= 'a' && fixedString[i] <= 'f') 
			{
				bytestring[j] = ((fixedString[i] - 0x57) << 4);

				if (fixedString[i + 1] >= 'A' && fixedString[i + 1] <= 'F')
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x37);
				else if (fixedString[i + 1] >= '0' && fixedString[i + 1] <= '9')
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x30);
				else if (fixedString[i + 1] >= 'a' && fixedString[i + 1] <= 'f')
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x57);

			}
			else if (fixedString[i] >= '0' && fixedString[i] <= '9') {

				bytestring[j] = ((fixedString[i] - 0x30) << 4);

				if (fixedString[i + 1] >= 'A' && fixedString[i + 1] <= 'F')
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x37);
				else if (fixedString[i + 1] >= '0' && fixedString[i + 1] <= '9')
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x30);
				else if (fixedString[i + 1] >= 'a' && fixedString[i + 1] <= 'f')
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x57);

			}
			else if (fixedString[i] >= 'A' && fixedString[i] <= 'F') {

				bytestring[j] = ((fixedString[i] - 0x37) << 4);

				if (fixedString[i + 1] >= 'A' && fixedString[i + 1] <= 'F') 
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x37);				
				else if (fixedString[i + 1] >= '0' && fixedString[i + 1] <= '9') 
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x30);			
				else if (fixedString[i + 1] >= 'a' && fixedString[i + 1] <= 'f') 
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x57);				
			}

			j++;
			i++;
		}
	}

	delete[] fixedString;
	return bytestring;
}

std::string PacketHelper::ToString(LPBYTE packetStr, int byteLength)
{
	if (byteLength < 4  || byteLength > 4096 || packetStr == NULL)
		return "";

	std::string newStr;
	CHAR* convertStr = (CHAR*)malloc((byteLength * 3) + 1); //* 3 since 00[ ] an extra 0 with a space for each byte in the str.

	for (int i = 0; i < byteLength; i++) {
		byte ch = packetStr[i];
		sprintf(&convertStr[i], "%.2X", ch);
		newStr.append(&convertStr[i]);
		newStr.append(" ");
	}

	free(convertStr);
	return newStr;
}

int PacketHelper::GetPacketLength(const CHAR* input)
{
	int length = 0;

	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == ' ')
			length = length;
		else
			length++;
	}

	length = length / 2;

	return length;
}

BOOL PacketHelper::CreatePacket(LPBYTE data, UINT length, BOOL isSendPacket)
{
	if (length < 0 || length > 4096 || data == nullptr || !g_LoggingSendPackets)
		return FALSE;

	bool shouldLogPacket = true;
	uint16_t Opcode = 0;
	
	memcpy(&Opcode, (void*)&data[2], sizeof(uint16_t));

	uint16_t OriginalOpcode = Opcode;
	Opcode = changeEndianness16(Opcode);

	for (auto & element : ModifyList) {

		if ((uint16_t)element->opcode == (uint16_t)OriginalOpcode) { //found modified

			bool patternMatches = false; //use this later when implementing patterns

			printf("Copying modify rule...\n");

			for (int i = 0; i < element->length - 2; i++) //-2 length for opcode
			{
				if (element->replacement[i] == (BYTE)'?') //wildcard byte
				{
					byte wildcard = (byte)rand_lim(255);
					element->replacement[i] = wildcard; //todo: change this to using both pattern and replacement for best results
				}

				data[7 + i] = element->replacement[2 + i]; //copy data
			}

			memcpy((void*)&data[5], (void*)&element->replacement[0], element->length);	
		}
	}

	for (auto & element : IgnoredList)
		if ((uint16_t)element == (uint16_t)Opcode) //found ignored
			return FALSE;

	BYTE* bPacketWithHeader = new BYTE[length + 2];
	memcpy((void*)bPacketWithHeader, (void*)&length, sizeof(uint16_t));
	memcpy((void*)&bPacketWithHeader[2], (void*)data, sizeof(byte)*length);

	if (shouldLogPacket)
	{
		PacketWriter* p = new PacketWriter();

		if (p != nullptr)
		{
			for (int i = 0; i < length + 2; i++)
				p->Write<byte>(bPacketWithHeader[i]);

			if (isSendPacket)
				SendPacketQueue.push(p);
			else
				RecvPacketQueue.push(p);
		}
	}

	delete[] bPacketWithHeader;
	return TRUE;
}

uint16_t PacketHelper::changeEndianness16(UINT16 val)
{
	return (val << 8) | ((val >> 8) & 0x00ff); // right-shift sign-extends, so force to zero
}


int32_t PacketHelper::changeEndianness32(int32_t val)
{
	int32_t tmp = (val << 16) |
		((val >> 16) & 0x00ffff);
	return ((tmp >> 8) & 0x00ff00ff) | ((tmp & 0x00ff00ff) << 8);
}

std::string PacketHelper::randomStr(size_t size)
{
	std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	std::random_device rd;
	std::mt19937 generator(rd());

	std::shuffle(str.begin(), str.end(), generator);

	return str.substr(0, size);    // assumes 32 < number of characters in str         
}

std::wstring PacketHelper::randomWStr(size_t size)
{
	std::wstring str(L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	std::random_device rd;
	std::mt19937 generator(rd());

	std::shuffle(str.begin(), str.end(), generator);

	return str.substr(0, size);    // assumes 32 < number of characters in str         
}

BOOL PacketHelper::WriteToFile(PacketWriter* p, wchar_t* fileName, bool isSend)
{
	if (p == nullptr)
		return false;

	if (p->GetBuffer() == NULL || p->GetSize() == 0)
		return false;

	std::string pStr = ToString((LPBYTE)p->GetBuffer(), p->GetSize());
	std::string cutStr = pStr.substr(15);

	std::ofstream myfile;
	myfile.open(fileName, std::ios::app);

	if (isSend)	
		myfile << "[SEND] " << cutStr.c_str() << "\r\n";
	else	
		myfile << "[RECV] " << cutStr.c_str() << "\r\n";
	

	myfile.close();

	return TRUE;
}