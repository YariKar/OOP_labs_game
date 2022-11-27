#include "message.h"
Message::Message(std::string level,std::string message)
{
    if (this->map_levels.find(level) != map_levels.end())
    {
        this->level = this->map_levels[level];
        this->message = level + "_log_" + message;
    }
    else
    {
        this->message = "Ошибка переданного уровня логирования";
    }
    //std::cout<<this->message<<'\n';
}
std::ostream& operator<<(std::ostream& out, const Message& obj)
{
    out << (obj.message)<<std::endl;
    return out;
}
int Message::GetLevel()
{
    return level;
}
std::string Message::FindKey(int value)
{
    for(std::map<std::string,int>::iterator it = this->map_levels.begin(); it!=this->map_levels.end(); ++it)
    {
        if (it->second == value)
        {
            return it->first;
        }
    }
    return "";
}