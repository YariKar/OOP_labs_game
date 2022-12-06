#include "direct_transform.h"
std::map<std::string,char> Direct_Transform::Transform_Command(std::string direct_commands)
{
    //std::cout<<"dc: "<<direct_commands<<'\n';
    std::map<std::string,char> commands;
    std::map<std::string,char>& com_link = commands;
    std::map<std::string,char> default_commands {{"UP",'w'},{"DOWN",'s'}, {"LEFT",'a'},{"RIGHT",'d'},{"START",'n'},{"SAVE",'x'}, {"LOAD",'l'}, {"EXIT",'q'}}; //лучше копия дефолт словаря
    //std::cout<<direct_commands;
    if (direct_commands!="\0") //сюда добавить условий проверки хорошести поступившей строки
    {
    direct_commands = Input_Map(com_link,"UP",direct_commands);
    direct_commands = Input_Map(com_link,"LEFT",direct_commands);
    direct_commands = Input_Map(com_link,"DOWN",direct_commands);
    direct_commands = Input_Map(com_link,"RIGHT",direct_commands);
    direct_commands = Input_Map(com_link,"START",direct_commands);
    direct_commands = Input_Map(com_link,"SAVE",direct_commands);
    direct_commands = Input_Map(com_link,"LOAD",direct_commands);
    direct_commands = Input_Map(com_link,"EXIT",direct_commands);
    if (IsSuccsessFill(commands))
    {
        return commands;
    }
    }
    //добавить сравнение заполненного словаря с дефолтным на предмет повторяющихся либо пустых команд
    return default_commands;
}
std::string Direct_Transform::Input_Map(std::map<std::string,char>& commands,std::string key,std::string direct_commands)
{
    int ind = direct_commands.find('=');
    commands[key] = direct_commands[ind+2];
    if (ind==-1)
    {
        commands[key]= ' ';
        direct_commands = "";
    }
    direct_commands = &direct_commands[ind+4];
    return direct_commands;
}
bool Direct_Transform::IsSuccsessFill(std::map<std::string,char> commands)
{
    for(std::map<std::string,char>::iterator it = commands.begin(); it!=commands.end(); ++it)
    {
        if(isupper(it->second)|| it->second == ' ' || it->second == '\n' || it->second == '=')
        {
            return false;
        }
        for(std::map<std::string,char>::iterator secit = commands.begin(); secit!=commands.end(); ++secit)
        {
            if (it->first!= secit->first && it->second == secit->second)
            {
                return false;
            }
        }
    }
    return true;
}