#ifndef BLIND_TRAP_H
#define EAT_BLIND_TRAP_H
#include "change_player.h"
#include "../different/event_mediator.h"
class Blind_Trap: public Change_Player::Change_Player
{
    public: 
        //~Blind_Trap();
        void event(Event_Mediator* mediator);
};
#endif