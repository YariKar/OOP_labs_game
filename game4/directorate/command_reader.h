#pragma once
#include "direct_transform.h"
#include "../incl.h"

class Command_Reader
{
    public:
        virtual ~Command_Reader() = default;
        virtual std::map<std::string,char> Read_Command() =0;
};