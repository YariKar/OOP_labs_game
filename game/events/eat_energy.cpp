#include "../incl.h"
#include "../field/field.h"
#include "../field/cell.h"
#include "../player/player.h"
#include "change_player.h"
#include "eat_energy.h"
#include "../different/event_mediator.h"
void Eat_Energy::event(Event_Mediator* mediator)
{
   if(mediator->GetPlayer()->GetEnergy()<mediator->GetPlayer()->GetMaxEnergy())
   {
      mediator->GetPlayer()->EatEnergy();
      //std::cout<<"Eat energy\n";
   }
}