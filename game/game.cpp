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
#include "exeptions/file_load_exeption.h"
#include "exeptions/game_load_exeption.h"
Game::Game()
{
    
    
}
void Game::Game_Process()
{

    //observer = new Observer();
    Tracked_Object::SetObserver(observer);
    //controller = new Controller(observer);
    if(!field)
    {
        controller->PutFieldSize();
        std::cout<<"Идет генерация карты. Пожалуйста, подождите.\n";
        field = Choose_Level(controller->Choose_Level(),observer,controller->GetFieldWidth(),controller->GetFieldHeight());
    }
    
    //field= new Field(observer,controller->GetFieldWidth(),controller->GetFieldHeight());
    //system("clear");
    view = new View(field->GetFieldWidth(),field->GetFieldHeight());
    //mediator = new Mediator();
    if(!player)
    {
        player = new Player(observer,field->GetFieldHeight()*field->GetFieldWidth());
    }
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
        try
        {
            mediator->Game_Condition(this,controller->GetDir());
        }
        catch (Game_Load_Exeption &e)
        {
            std::cout<<e.what()<<'\n';
        }
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
    if(level_generator)
        delete level_generator;
    field = nullptr;
    player = nullptr;
    level_generator = nullptr;
}
void Game::Menu()
{
    file_saver = new File_Saver(); 
    observer = new Observer();
    controller = new Controller(observer);
    menu_view = new Menu_View();
    mediator = new Mediator();
    caretaker = new Caretaker();
    menu_play = true;
    try
    {
        file_saver->Load_From_File(caretaker);
    }
    catch(File_Load_Exeption& e)
    {
        std::cout<<e.what()<<'\n';
    }
    
    
    while(menu_play)
    {
        menu_view->Print_Directorate(mediator);
        menu_view->Draw_Menu();
        controller->PutMove();
        try 
        {
            mediator->Menu_Conditions(this,controller->GetDir());
        }
        catch(Game_Load_Exeption& e)
        {
            std::cout<<e.what()<<'\n';
        }
        while(load)
        {
            try 
            {
                Load();
            }
            catch(Game_Load_Exeption& e)
            {
                std::cout<<e.what()<<'\n';
            }
            
        }
        //system("clear");
    }
}
void Game::Menu_Exit()
{
    menu_play = false;
    file_saver->Save_In_Files(caretaker);
}
void Game::Game_Exit()
{
    play = false;
}
Field* Game::Choose_Level(int level,Observer* observer, int width, int height)
{
    switch (level)
    {
    case 1:
        level_generator = new Level_One();
        return level_generator->Generate_Level(observer,width,height);
        break;
    case 2:
        level_generator = new Level_Two();
        return level_generator->Generate_Level(observer,width,height);
        break;
    default:
        break;
    }
    return nullptr;
}
void Game::Save()
{
    caretaker->SetFieldMemnto(field->save());
    caretaker->SetPlayerMemnto(player->save());
}
void Game::Load()
{
    /*if(field!=nullptr)
    {
        delete field;
    }
    if(player!=nullptr)
    {
        delete player;
    }*/
    load = false;
    if(!caretaker->GetPlayerMemento()||!caretaker->GetFieldMemento())
    {
        throw Game_Load_Exeption();
    }
    player = new Player(observer);
    player->load(caretaker->GetPlayerMemento());
    //std::cout<<"here "<<caretaker->GetFieldMemento()->GetFieldSize().second<<caretaker->GetFieldMemento()->GetFieldSize().first<<'\n';
    field = new Field(observer,caretaker->GetFieldMemento()->GetFieldSize().second, caretaker->GetFieldMemento()->GetFieldSize().first);
    field->load(caretaker->GetFieldMemento());
    
    Game_Process();
    
}
void Game::Do_Load()
{
    if(!caretaker->GetPlayerMemento()||!caretaker->GetFieldMemento())
    {
        throw Game_Load_Exeption();
    }
    load = true;
    Game_Exit();
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
    delete caretaker;
    delete file_saver;
}

//Game::~Game(){}
