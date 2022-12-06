#pragma once
#include "../../incl.h"
#include "../message.h"
#include "log.h"
class Log_File: public Log
{
    private:
        std::ofstream out;
    public:
        Log_File(const char* filename);
        ~Log_File();
        void Update(Message* message);
};