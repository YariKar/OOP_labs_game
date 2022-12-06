#pragma once
#include "../../field/field.h"
template<int count>
class Event_Num
{
    public:
        void declare(Field* field);
};
template<int count>
void Event_Num<count>::declare(Field* field)
{
    int standart_count = int(field->GetFieldHeight()*field->GetFieldWidth()/8);
    if (count > standart_count||count < 0)
    {
        field->SetEventCount(standart_count);
    }
    else
    {
        field->SetEventCount(count);
    }

}