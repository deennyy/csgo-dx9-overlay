#include "overlay.h"
#include "cheat.h"

c_memory* memory;

int main() {
	FreeConsole();

	memory = new c_memory(data::game_name);

	cheat::startup();

	overlay::run();

	delete memory;

	return EXIT_SUCCESS;
}