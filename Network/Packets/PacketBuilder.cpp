#include "PacketBuilder.hpp"

extern BOOL g_LoggingSendPackets;
extern std::queue<PacketWriter*> SendPacketQueue;

PacketWriter* PacketBuilder::CheckCharacterName(string name)
{
	PacketWriter* p;
	return p;
}

int PacketBuilder::EncryptPacket(LPVOID pPacketClass, LPBYTE buffer, int length)
{
	uint64_t module = (uint64_t)GetModuleHandle(NULL); 
	typedef int(*Encrypt)(LPVOID _class, LPBYTE _buffer, int _length, LPBYTE _buffer2);
	Encrypt _enc;
	_enc = (Encrypt)(module + Offsets::EncryptPacket);
	return _enc(pPacketClass, buffer, length, buffer); //checks if pPacketClass is 0
}
