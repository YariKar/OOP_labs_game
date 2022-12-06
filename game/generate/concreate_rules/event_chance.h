#pragma once
#include "../../field/field.h"
#include "../../incl.h"

template<int ea_chance,int bt_chance, int ow_chance, int rf_chance>
class Event_Chance
{
    public:
        void declare(Field* field);
};

template<int ea_chance,int bt_chance, int ow_chance, int rf_chance>
void Event_Chance<ea_chance, bt_chance, ow_chance, rf_chance>::declare(Field* field)
{
    int* chances = new int (COUNT_EVENT_TYPE);
    if (ea_chance+bt_chance+ow_chance+rf_chance==100)
    {
        //chances = {ea_chance,bt_chance,ow_chance,rf_chance};
        chances[0] = ea_chance;
        chances[1] = bt_chance;
        chances[2] = ow_chance;
        chances[3] = rf_chance;
    }
    else
    {
        chances[0] = int(100/COUNT_EVENT_TYPE);
        chances[1] = int(100/COUNT_EVENT_TYPE);
        chances[2] = int(100/COUNT_EVENT_TYPE);
        chances[3] = int(100/COUNT_EVENT_TYPE);
    }
    
    field->SetEventChance(chances);
}