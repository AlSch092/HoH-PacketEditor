#pragma once
#include "Network/Packets/PacketParsing.hpp"
#include <stdint.h>

extern std::queue<PacketWriter*> SendPacketQueue;
extern std::queue<PacketWriter*> RecvPacketQueue;

namespace Hooks
{
	VOID InstallHook(void* func2hook, void* payloadFunction);
	VOID WriteAbsoluteJump64(void* absJumpMemory, void* addrToJumpTo);
	VOID RemoveHook(UINT64 HookAddress, INT ByteLength, BYTE* OriginalBytes);
	VOID* AllocatePageNearAddress(void* targetAddr);

	BOOL hk_EncryptPacket(BYTE* data, INT Length); //send packet
	BOOL hk_CPacketHandler_AddPacket(BYTE* data, INT Length); //recv packet
}