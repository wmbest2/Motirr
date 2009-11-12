#pragma once
#include <irrlicht.h>

class CGame {

public:
    ~CGame(void);
    static CGame* getGameInstance();

    irr::scene::ISceneManager* getSceneManager();

    void initGame();

    void Run();


private:
    CGame();
    static CGame* instance;

    irr::IrrlichtDevice *device;
    irr::video::IVideoDriver* driver;
    irr::scene::ISceneManager* smgr;

    
};
