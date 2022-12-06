#include "observer.h"
#include "../incl.h"

void Observer::SetMessage(Message* message)
{
    this->message = message;
    cur_log_level = message->GetLevel();
    TransferLog();
}
void Observer::Set_Logs_Level(std::map<std::string,bool> logs, std::map<std::string, bool> level)
{
    this->logs = logs;
    this->level = level;
    //std::cout<<logs["file"]<<' '<<logs["console"]<<' '<<level["info"]<<' '<<level["game"]<<' '<<level["error"]<<'\n';

}
Observer::Observer()
{
    log_console = new Log_Console();
    log_file = new Log_File("logging/concrete_logs/file_with_logs/log_file.txt");
}
Observer::~Observer()
{
    delete log_console;
    delete log_file;
}
void Observer::TransferLog()
{
    if (level[this->message->FindKey(cur_log_level)])
    {
        if (logs["file"])
        {
            log_file->Update(message);
        }
        if (logs["console"])
        {
            log_console->Update(message);
        }
    }
}