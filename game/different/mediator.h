#ifndef MEDIATOR_H
#define MEDIATOR_H
#include "../field/field.h"
//#include "../logging/tracked_object.h"
#include "../logging/observer.h"
#include "../directorate/command_reader.h"
#include "../directorate/file_reader.h"
class Game;
class Mediator
{
    private:
        std::map<std::string,char> command;
        Command_Reader* reader;
        //Command_Reader<std::ifstream> reader;
    public: 
        Mediator();
        //Mediator(Observer* observer);
        ~Mediator();
        void Move(Field* field, char dir);
        void Game_Condition(Game* game,char dir);
        void Menu_Conditions(Game* game,char dir);
        std::map<std::string,char> GetMap();
};  

#endif