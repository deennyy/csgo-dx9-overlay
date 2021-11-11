#include "cheat.h"

vec3 cheat::w2s(const vec3 pos) {
	auto matrix = memory->read<matrix4x4>(modules::client.base + offsets::dwViewMatrix);

	vec3 out;
	float _x = matrix.matrix[0] * pos.x + matrix.matrix[1] * pos.y + matrix.matrix[2] * pos.z + matrix.matrix[3];
	float _y = matrix.matrix[4] * pos.x + matrix.matrix[5] * pos.y + matrix.matrix[6] * pos.z + matrix.matrix[7];
	out.z = matrix.matrix[12] * pos.x + matrix.matrix[13] * pos.y + matrix.matrix[14] * pos.z + matrix.matrix[15];

	_x *= 1.f / out.z;
	_y *= 1.f / out.z;

	int width = 1920;
	int height = 1080;

	out.x = width * .5f;
	out.y = height * .5f;

	out.x += 0.5f * _x * width + 0.5f;
	out.y -= 0.5f * _y * height + 0.5f;

	return out;
}

void cheat::startup() {
	modules::engine = memory->get_module(L"engine.dll");
	modules::client = memory->get_module(L"client.dll");

	if (!data::should_continue)
		return;

	offsets::dwClientState = memory->pattern_scan(modules::engine, L"A1 ? ? ? ? 33 D2 6A 00 6A 00 33 C9 89 B0", 0x1, 0x0, true, true);
	offsets::dwClientState_GetLocalPlayer = memory->pattern_scan(modules::engine, L"8B 80 ? ? ? ? 40 C3", 0x2, 0x0, true, false);
	offsets::dwEntityList = memory->pattern_scan(modules::client, L"BB ? ? ? ? 83 FF 01 0F 8C ? ? ? ? 3B F8", 0x1, 0x0, true, true);
	offsets::m_bDormant = memory->pattern_scan(modules::client, L"8A 81 ? ? ? ? C3 32 C0", 0x2, 0x8, true, false);
	offsets::dwViewMatrix = memory->pattern_scan(modules::client, L"0F 10 05 ? ? ? ? 8D 85 ? ? ? ? B9", 0x3, 0xB0, true, true);

	globals::client_state = memory->read<DWORD>(modules::engine.base + offsets::dwClientState);
}