#include "file_reader.h"
#include "../incl.h"

File_Reader::File_Reader(std::string name)
{
    input.open(name,std::ios::in);
}


File_Reader::~File_Reader()
{
    input.close();
}

std::map<std::string,char> File_Reader::Read_Command()
{
    std::string line;
    std::string file_commands;
    if (input.is_open())
    {
        getline(input,line);
        while(getline(input,line))
        {
            file_commands+=line+'\n';
        }
    }
    Direct_Transform transform = Direct_Transform();
    std::map<std::string,char> commands = transform.Transform_Command(file_commands);
    return commands;
}