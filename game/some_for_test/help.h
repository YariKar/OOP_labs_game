#pragma once
#include <iostream>

template<typename T>
class Command_Reader
{
    private:
        T input;
    public:
        Command_Reader(T input);
        void print();
        
};

#include "help_realize.h"