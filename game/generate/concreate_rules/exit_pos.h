#pragma once
#include "../../field/field.h"
template<bool flag>
class Exit_Pos
{
    public:
        void declare(Field* field);
};
template<bool flag>
void Exit_Pos<flag>::declare(Field* field)
{
    if (!flag)
    {
        return;
    }
    field->Notify("info","Создание клетки победы");
    field->RandWin();
}