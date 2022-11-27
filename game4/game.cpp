#include "incl.h"
#include "game.h"
#include "field/field.h"
#include "field/cell.h"
#include "output/view.h"
#include "input/controller.h"
#include "player/player.h"
#include "different/mediator.h"
#include "different/event_mediator.h"
#include "logging/message.h"
#include "output/menu_view.h"
#include "input/input.h"
Game::Game()
{
    
    
}
void Game::Game_Process()
{
    //observer = new Observer();
    Tracked_Object::SetObserver(observer);
    //controller = new Controller(observer);
    controller->PutFieldSize();
    std::cout<<"Идет генерация карты. Пожалуйста, подождите.\n";
    field= new Field(observer,controller->GetFieldWidth(),controller->GetFieldHeight());
    //system("clear");
    view = new View(field->GetFieldWidth(),field->GetFieldHeight());
    //mediator = new Mediator();
    player = new Player(observer,field->GetFieldHeight()*field->GetFieldWidth());
    event_mediator = new Event_Mediator(field,player);
    if(field->IsWin())
    {   
        Notify("error","Координаты игрока совпали с координатами победы");
    }
    int blind_counter= 5;
    int off_walls_counter = 5;
    Notify("game","Начало игры");
    play = true;
    while(play && player->GetEnergy()>0 && !field->IsWin())
    {
        
        if(player->GetBlindMode())
        {
            blind_counter--;
            if(blind_counter == 0)
            {
                player->OffBlindMode();
                blind_counter = 5;
            }
        }
        if(!field->GetIsWalls())
        {
            off_walls_counter--;
            if(off_walls_counter == 0)
            {
                field->OnWalls();
                off_walls_counter = 5;
            }
        }
        field->OpenCells(player); 
        view->DrawWindow(field);   
        view->DrawStats(player);
        controller->PutMove();
        mediator->Move(field,controller->GetDir());
        mediator->Game_Condition(this,controller->GetDir());
        if (field->GetField()[field->GetPlY()][field->GetPlX()]->IsEvent())
        {
            field->GetField()[field->GetPlY()][field->GetPlX()]->GetEvent()->event(event_mediator);
            field->GetField()[field->GetPlY()][field->GetPlX()]->DestroyEvent();
        }
        
        //std::cout<<'\n';
        //system("clear");
        player->Waste_Energy();
        if(field->IsWin())
        {
            Notify("game","Достигнуты условия победы");
            std::cout<<"Вы выиграли ураааааа!\n";       
        }
        if(player->GetEnergy()==0)
        {
            Notify("game","Достигнуты условия поражения");
            std::cout<<"Вы проиграли\n";
            
        }  
    } 
    delete event_mediator;
    delete player;
    delete view;
    delete field;
}
void Game::Menu()
{
    observer = new Observer();
    controller = new Controller(observer);
    menu_view = new Menu_View();
    mediator = new Mediator();
    menu_play = true;
    while(menu_play)
    {
        menu_view->Print_Directorate(mediator);
        menu_view->Draw_Menu();
        controller->PutMove();
        mediator->Menu_Conditions(this,controller->GetDir());
        //system("clear");
    }
}
void Game::Menu_Exit()
{
    menu_play = false;
}
void Game::Game_Exit()
{
    play = false;
}
Game::~Game()
{
    /*if(event_mediator)
        delete  event_mediator;
    if(player)
        delete  player;
    if(view)
        delete  view; 
    if(field)
        delete field;*/
    delete mediator;
    delete controller;
    delete observer;
    delete menu_view;
    
   
}

//Game::~Game(){}
