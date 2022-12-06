#pragma once
#include "../../field/field.h"
template<bool flag>
class Way_Generate
{
    public:
        void declare(Field* field);
};
template<bool flag>
void Way_Generate<flag>::declare(Field* field)
{
    if (!flag)
    {
        return;
    }
    field->Notify("info","Создание ирового поля");
    field->RandField(field->GetPlX(),field->GetPlY());
}