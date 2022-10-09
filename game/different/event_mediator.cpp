
#include "../incl.h"
#include "../field/field.h"
#include "../field/cell.h"
#include "../player/player.h"
#include "event_mediator.h"
Event_Mediator::Event_Mediator(Field* field, Player* player) 
    {
        this->field = field;
        this->player = player;
    }

Field* Event_Mediator::GetField()
{
    return field;
}
Player* Event_Mediator::GetPlayer()
{
    return player;
}