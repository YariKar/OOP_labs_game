#pragma once
#include "../incl.h"
class Direct_Transform
{
    private:
        std::string Input_Map(std::map<std::string,char>& commands,std::string key,std::string direct_commands);
        bool IsSuccsessFill(std::map<std::string,char> commands);
    public:
        
        std::map<std::string,char> Transform_Command(std::string direct_commands);
};