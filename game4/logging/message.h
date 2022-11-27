#pragma once
#include "../incl.h"
class Message
{
    private:
        std::map<std::string,int> map_levels { {"info",1}, {"game",2}, {"error",3}};
        int level;
        std::string message;
    public:
        Message(std::string level, std::string message);
        int GetLevel();
        std::string FindKey(int value);
        friend std::ostream& operator<<(std::ostream& out, const Message& obj);
};
std::ostream& operator<<(std::ostream& out, const Message& obj);
