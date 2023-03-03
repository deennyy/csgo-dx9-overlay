#include "data.h"

namespace modules {
	s_module client, engine = { NULL, NULL };
};

namespace offsets {
	DWORD dwClientState, dwClientState_GetLocalPlayer, dwEntityList, dwViewMatrix = NULL;
	DWORD m_iTeamNum = 0xF4;
	DWORD m_vecOrigin = 0x138;
	DWORD m_bDormant = 0xED;
	DWORD m_iHealth = 0x100;
}

namespace globals {
	DWORD client_state = NULL;
}

namespace data {
	LPCWSTR game_name = L"Counter-Strike: Global Offensive - Direct3D 9";
	bool should_continue = true;
	int screen_x = 0;
	int screen_y = 0;
};