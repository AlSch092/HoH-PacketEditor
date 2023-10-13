#pragma once
#include "PacketBuilder.hpp"
#include <iostream>
#include <list>
#include <queue>
#include <random>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_BUFFER_LENGTH 4096*3

namespace PacketHelper
{
	int rand_lim(int limit);

	std::string randomStr(size_t size);
	std::wstring randomWStr(size_t size);

	uint16_t changeEndianness16(UINT16 val);
	int32_t changeEndianness32(int32_t val);

	LPBYTE ToPacketFormat(CHAR* input);
	std::string ToString(LPBYTE packetStr, int byteLength);

	int GetPacketLength(const CHAR* input);

	BOOL CreatePacket(LPBYTE data, UINT length, BOOL isSendPacket);

	BOOL WriteToFile(PacketWriter* p, wchar_t* fileName, bool isSend);
};

struct ModifyRule {
	int length;
	BYTE* pattern;
	BYTE* replacement;
	uint16_t opcode;
};
