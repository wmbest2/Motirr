#pragma once
#include <irrlicht.h>

class CGameEventReceiver :
    public irr::IEventReceiver
{
public:
    CGameEventReceiver(void);
    ~CGameEventReceiver(void);
};
