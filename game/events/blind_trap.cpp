#include "../incl.h"
#include "../field/field.h"
#include "../field/cell.h"
#include "../player/player.h"
#include "change_player.h"
#include "blind_trap.h"
#include "../different/event_mediator.h"
void Blind_Trap::event(Event_Mediator* mediator)
{
   mediator->GetPlayer()->OnBlindMode();
   //std::cout<<"Blind mode\n";
}