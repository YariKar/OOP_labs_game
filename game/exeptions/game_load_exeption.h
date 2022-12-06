#pragma once
#include <string>
class Game_Load_Exeption: public std::exception
{
    public:
        Game_Load_Exeption() = default;
        std::string what();
};