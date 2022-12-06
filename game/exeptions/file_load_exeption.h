#pragma once
#include <string>
class File_Load_Exeption: public std::exception
{
    private:
        std::string filename = "";
    public:
        File_Load_Exeption(std::string filename);
        File_Load_Exeption();
        std::string what();
};