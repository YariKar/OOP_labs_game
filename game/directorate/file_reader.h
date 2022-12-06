#pragma once
#include "direct_transform.h"
#include "command_reader.h"
#include "../incl.h"

class File_Reader: public Command_Reader
{
    private:
        std::ifstream input;
    public:
        File_Reader(std::string name);
        ~File_Reader();
        std::map<std::string,char> Read_Command();
};