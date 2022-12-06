#include "caretaker.h"
#include "../memento/memento.h"
#include "../memento/player_memento.h"
#include "../memento/field_memento.h"
Field_Memento* Caretaker::GetFieldMemento()
{
    return field_memento;
}
Player_Memento* Caretaker::GetPlayerMemento()
{
    return player_memento;
}
void Caretaker::SetFieldMemnto(Field_Memento* memento)
{
    if(field_memento!=nullptr)
    {
        delete field_memento;
    }
    field_memento = memento;
}
void Caretaker::SetPlayerMemnto(Player_Memento* memento)
{
    if(player_memento!=nullptr)
    {
        delete player_memento;
    }
    player_memento = memento;
}