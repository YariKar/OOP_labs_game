#ifndef CHANGE_PLAYER_H
#define CHANGE_PLAYER_H
#include "event.h"
#include "../different/event_mediator.h"
class Change_Player : public Event::Event
{
    public:
        //virtual~ Change_Player() = 0;
        virtual void event(Event_Mediator* mediator)= 0;
};
#endif