#pragma once

#include <Windows.h>

struct s_module {
	DWORD base, size;
};

struct vec3 {
	float x, y, z;
};

struct matrix4x4 {
	float matrix[16];
};

namespace modules {
	extern s_module client, engine;
};

namespace offsets {
	extern DWORD dwClientState, dwClientState_GetLocalPlayer, dwEntityList, m_bDormant, m_iTeamNum, dwViewMatrix, m_vecOrigin, m_iHealth;
}

namespace globals {
	extern DWORD client_state;
}

namespace data {
	extern LPCWSTR game_name;
	extern bool should_continue;
	extern int screen_width;
	extern int screen_height;
	extern int cs_window_width;
	extern int cs_window_height;
	extern int cs_window_x;
	extern int cs_window_y;
};