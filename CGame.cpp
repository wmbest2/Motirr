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

    scene::IParticleSystemSceneNode* ps =
		smgr->addParticleSystemSceneNode(false);

	scene::IParticleEmitter* em = ps->createRingEmitter(
		core::vector3df(0.0f,0.1f,0.0f), // emitter size
        10, 1,
		core::vector3df(0.0f,0.02f,0.0f),   // initial direction
		80,100,                             // emit rate
		video::SColor(0,0,0,0),       // darkest color
		video::SColor(0,255,255,255),       // brightest color
		800,1000,0,                         // min and max age, angle
		core::dimension2df(50.f,60.f),         // min size
		core::dimension2df(60.f,60.f));        // max size

	ps->setEmitter(em); // this grabs the emitter
	em->drop(); // so we can drop it here without deleting it

	scene::IParticleAffector* paf = ps->createFadeOutParticleAffector();

	ps->addAffector(paf); // same goes for the affector
	paf->drop();

	ps->setPosition(core::vector3df(-70,60,40));
	ps->setScale(core::vector3df(2,2,2));
	ps->setMaterialFlag(video::EMF_LIGHTING, false);
	ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, driver->getTexture("C:/Documents and Settings/bbest/My Documents/irrlicht-1.6/media/portal1.bmp"));
	ps->setMaterialType(video::EMT_TRANSPARENT_VERTEX_ALPHA);

    scene::ICameraSceneNode* camera = smgr->addCameraSceneNodeFPS();
	camera->setPosition(core::vector3df(-50,50,-150));


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