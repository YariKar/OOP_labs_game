#pragma once
#include "../../incl.h"
#include "../message.h"
#include "log.h"
class Log_Console: public Log
{
    public:
        void Update(Message* message);
        ~Log_Console();
};