#pragma once
#include <irrlicht.h>

class CGameEventReciever :
    public irr::IEventReciever
{
public:
    CGameEventReciever(void);
    ~CGameEventReciever(void);
};
