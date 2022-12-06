#pragma once

//#include "../memento/memento.h"
class Memento;
class Player_Memento;
class Field_Memento;
class Caretaker
{
    private:
        Player_Memento* player_memento = nullptr;
        Field_Memento* field_memento = nullptr;
    public:
        Player_Memento* GetPlayerMemento();
        Field_Memento* GetFieldMemento();
        void SetPlayerMemnto(Player_Memento* memento);
        void SetFieldMemnto(Field_Memento* memento);
};