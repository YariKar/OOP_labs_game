#ifndef OBSERVER_H
#define OBSERVER_H
#include "../incl.h"
#include "message.h"
#include "concrete_logs/log_console.h"
#include "concrete_logs/log_file.h"
#include "concrete_logs/log.h"
class Observer
{
    private:
        std::map<std::string,bool> logs;
        std::map<std::string,bool> level;
        int cur_log_level;
        Message* message;
        Log* log_file;
        Log* log_console;
        void TransferLog();
    public:
        Observer();
        ~Observer();
        void SetMessage(Message* message);
        void Set_Logs_Level(std::map<std::string,bool> logs, std::map<std::string, bool> level); 
};
#endif