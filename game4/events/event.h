#ifndef EVENT_H
#define EVENT_H
#include "../different/event_mediator.h"
//#include "../field/field.h"
//#include "../player/player.h"
class Event
{
    public:
        //virtual ~Event() = default;
        virtual void event(Event_Mediator* mediator)= 0;
};
#endif