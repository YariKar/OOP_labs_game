#pragma once
#include "../../field/field.h"
class Level
{
    public:
        //virtual ~Level() =default;
        virtual Field* Generate_Level(Observer* observer,int width, int height) =0;
};