#include "log_console.h"
void Log_Console::Update(Message* message)
{
    std::cout<<*message;
}
Log_Console::~Log_Console()
{
    //std::cout<<"деструктор консольного лога\n";
}
