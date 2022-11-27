#include "menu_view.h"

void Menu_View::Draw_Menu()
{

    std::cout<<"\t\t\tМеню\n";
    std::cout<<"Начало игры\n";
    std::cout<<"Загрузить игру\n";
    std::cout<<"Выход\n";
    }
void Menu_View::Print_Directorate(Mediator* mediator)
{
    /*std::ifstream out;
    out.open("directorate/command_file.txt",std::ios::in);
    std::string line;
    while(getline(out,line))
    {
        std::cout<<line<<std::endl;
    }
    out.close();*/
    std::cout<<"UP = "<<mediator->GetMap()["UP"]<<'\n';
    std::cout<<"LEFT = "<<mediator->GetMap()["LEFT"]<<'\n';
    std::cout<<"DOWN = "<<mediator->GetMap()["DOWN"]<<'\n';
    std::cout<<"RIGHT = "<<mediator->GetMap()["RIGHT"]<<'\n';
    std::cout<<"START = "<<mediator->GetMap()["START"]<<'\n';
    std::cout<<"SAVE = "<<mediator->GetMap()["SAVE"]<<'\n';
    std::cout<<"LOAD = "<<mediator->GetMap()["LOAD"]<<'\n';
    std::cout<<"EXIT = "<<mediator->GetMap()["EXIT"]<<'\n';
}