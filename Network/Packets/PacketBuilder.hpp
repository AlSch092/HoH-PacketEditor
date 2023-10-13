#pragma once
#include <string>
#include <queue>
#include "PacketWriter.hpp"
#include "../../Dereference.hpp"
#include "../../Offsets.hpp"

using namespace std;

struct s_SendPacket //max length: 8192
{
	uint16_t length;
	uint16_t opcode;
	byte* data;
};

namespace PacketBuilder
{
	int EncryptPacket(LPVOID pPacketClass, LPBYTE buffer, int length); 

	PacketWriter* CheckCharacterName(string name);
	//PacketWriter* DeploySpirit(uint8_t Slot, uint16_t SpiritId);
	//PacketWriter* CharacterMovement(float x);
	//PacketWriter* CharacterAttack(uint8_t state, uint16_t skill, uint32_t attack_id, float loc_start, float loc_end, float attack_direction_vector, uint32_t* targets);
}

namespace Opcodes
{
	enum Send
	{
		CreateCharacter = 0x1429,
	};

	enum Recv
	{
	};
}

