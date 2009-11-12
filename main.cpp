#include <irrlicht.h>
#include "CGame.h"
#include <iostream>

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

using namespace irr;

int main() {

    CGame* game_instance = CGame::getGameInstance();

    game_instance->Run();

	return 0;

}