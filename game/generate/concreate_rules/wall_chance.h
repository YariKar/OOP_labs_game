#pragma once
#include "../../field/field.h"
template<int chance>
class Wall_Chance
{
    public:
        void declare(Field* field);
};

template<int chance>
void Wall_Chance<chance>::declare(Field* field)
{
    int standart_chance = 25;
   if(chance<0||chance>50)
   {
        field->SetWallChance(standart_chance);
   }
   else
   {
        field->SetWallChance(chance);
   }
}