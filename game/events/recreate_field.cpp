#include "../incl.h"
#include "../field/field.h"
#include "../field/field.h"
#include "../player/player.h"
#include "change_field.h"
#include "event.h"
#include "recreate_field.h"
#include "../different/event_mediator.h"
void Recreate_Field::event(Event_Mediator* mediator)
{
   mediator->GetField()->Recreate_Field();
   //std::cout<<"Recreate field\n";
}