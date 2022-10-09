#ifndef EAT_ENERGY_H
#define EAT_ENERGY_H
#include "change_player.h"
#include "../different/event_mediator.h"
class Eat_Energy: public Change_Player::Change_Player
{
    public:
        //~Eat_Energy();
        void event(Event_Mediator* mediator);
};
#endif