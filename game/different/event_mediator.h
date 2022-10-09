#ifndef EVENT_MEDIATOR_H
#define EVENT_MEDIATOR_H
/*#include "field.h"
#include "cell.h"
#include "player.h"*/
#include "../player/player.h"
//#include "field.h"
#include "../field/cell.h"
class Field;

class Event_Mediator
{
    private:
        Field* field;
        Player* player;
    public:
        Event_Mediator(Field* field,Player* player);
        Field* GetField();
        Player* GetPlayer();
};
#endif