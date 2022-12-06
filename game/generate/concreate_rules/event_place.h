#pragma once
#include "../../field/field.h"
template<bool flag>
class Event_Place
{
    public:
        void declare(Field* field);
};
template<bool flag>
void Event_Place<flag>::declare(Field* field)
{
    if (!flag)
    {
        return;
    }
    field->Notify("info","Создание событий");
    field->RandEventCoords();
}