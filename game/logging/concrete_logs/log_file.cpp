#include "log_file.h"
Log_File::Log_File(const char* filename)
{
    
    out.open(filename,std::ios::trunc);
}
Log_File::~Log_File()
{
    //std::cout<<"деструктор файлового лога\n";
    out.close();
}
void Log_File::Update(Message* message)
{
    out<<(*message);
}