#include "../incl.h"
#include "mediator.h"
#include "../game.h"
Mediator::Mediator()
{
    reader = new File_Reader("directorate/command_file.txt");
    command = reader->Read_Command();
    //std::cout<<command["UP"]<<' '<<command["LEFT"]<<' '<<command["DOWN"]<<' '<<command["RIGHT"]<<' '<<command["START"]<<' '<<command["SAVE"]<<' '<<command["LOAD"]<<' '<<command["EXIT"]<<'\n';
}
//Mediator::Mediator(){}
Mediator::~Mediator()
{
   delete reader;
}
void Mediator::Move(Field* field, char dir)
{
    if (dir == command["UP"])
    {
        field->MoveUp();
    }
    if (dir == command["LEFT"])
    {
        field->MoveLeft();
    }
    if (dir == command["DOWN"])
    {
        field->MoveDown();
    }
    if (dir == command["RIGHT"])
    {
        field->MoveRight();
    }
    //std::cout<<Field::player_x<<' '<<Field::player_y<<'\n';
}
void Mediator::Game_Condition(Game* game,char dir)
{
    if (dir==command["SAVE"])
    {
        std::cout<<"Функция сохранения будет добавлена позже\n";
    }
    if (dir==command["LOAD"])
    {
        std::cout<<"Функция загрузки будет добавлена позже\n";
    }
    if (dir == command["EXIT"])
    {
        game->Game_Exit();
    }
}
void Mediator::Menu_Conditions(Game* game, char dir)
{
    if (dir==command["START"])
    {
        game->Game_Process();
    }
    if (dir==command["LOAD"])
    {
        std::cout<<"Функция загрузки будет добавлена позже\n";
    }
    if (dir==command["EXIT"])
    {
        game->Menu_Exit();
    }
}
std::map<std::string,char> Mediator::GetMap()
{
    return command;
}
