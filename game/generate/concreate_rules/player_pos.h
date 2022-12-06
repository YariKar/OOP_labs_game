#pragma once
#include "../../field/field.h"
template<bool flag>
class Player_Pos
{
    public:
        void declare(Field* field);
};

template<bool flag>
void Player_Pos<flag>::declare(Field* field)
{
    if (!flag)
    {
        return;
    }
    field->RandPl();
}