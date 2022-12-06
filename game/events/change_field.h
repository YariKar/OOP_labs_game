#ifndef CHANGE_FIELD_H
#define CHANGE_FIELD_H
#include "event.h"
#include "../different/event_mediator.h"
//#include "../field/field.h"
class Change_Field: public Event::Event
{
    public:
        //virtual~ Change_Field() = default;
        virtual void event(Event_Mediator* mediator)= 0;
};
#endif