#ifndef OFF_WALLS_H
#define OFF_WALLS_H
#include "change_field.h"
#include "../different/event_mediator.h"
class Off_Walls: public Change_Field::Change_Field
{
    public:
        //~Off_Walls();
        void event(Event_Mediator* mediator);
};
#endif