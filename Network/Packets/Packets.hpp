#pragma once
#include "PacketBuilder.hpp"
#include "PacketWriter.hpp"
#include "PacketParsing.hpp"

extern "C"
{
	UINT64 g_LogSendPacketReturnAddress = 0;
	UINT64 g_LogSendPacketCallback = 0; //CreatePacket
	UINT64 g_SendKeyPtr = 0;
}