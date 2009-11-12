#include "CGame.h"

using namespace irr;

CGame* CGame::instance = 0;

CGame* CGame::getGameInstance() {
    if(!instance) {
        instance = new CGame();
        instance->initGame();
    }

    return instance;
}

CGame::CGame() {
    device = createDevice(video::EDT_DIRECT3D9, core::dimension2d<u32>(1024, 768), 16, false, false);

    driver = device->getVideoDriver();
	smgr = device->getSceneManager();

}

CGame::~CGame(void) {
}

void CGame::initGame() {

}

void CGame::Run() {
    // disable mouse cursor
	device->getCursorControl()->setVisible(false);

	s32 lastFPS = -1;

	while(device->run())
	if (device->isWindowActive())
	{
		driver->beginScene(true, true, 0);

		smgr->drawAll();

		driver->endScene();

		const s32 fps = driver->getFPS();

		if (lastFPS != fps)
		{
			core::stringw str = L"Motirr [";
			str += driver->getName();
			str += "] FPS:";
			str += fps;

			device->setWindowCaption(str.c_str());
			lastFPS = fps;
		}
	}

	device->drop();
}