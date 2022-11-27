#pragma once
#include "../message.h"
class Log
{
    public:
        virtual void Update(Message* message) = 0;
};