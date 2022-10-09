#ifndef RECREATE_FIELD_H
#define RECREATE_FIELD_H
#include "change_field.h"
#include "../different/event_mediator.h"
class Recreate_Field: public Change_Field::Change_Field
{
    public:
        //~Recreate_Field();
        void event(Event_Mediator* mediator);
};
#endif