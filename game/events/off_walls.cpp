#include "../incl.h"
#include "../field/field.h"
#include "../field/cell.h"
#include "../player/player.h"
#include "change_field.h"
#include "event.h"
#include "off_walls.h"
#include "../different/event_mediator.h"
void Off_Walls::event(Event_Mediator* mediator)
{
   mediator->GetField()->OffWalls();
   std::cout<<"Off Walls\n";
}