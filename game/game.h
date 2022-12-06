#ifndef GAME_H
#define GAME_H
#include "incl.h"
#include "field/field.h"
#include "field/cell.h"
#include "output/view.h"
#include "input/controller.h"
#include "player/player.h"
#include "different/mediator.h"
#include "different/event_mediator.h"
#include "logging/observer.h"
#include "logging/tracked_object.h"
#include "output/menu_view.h"
#include "input/input.h"
#include "generate/field_generator.h"
#include "generate/levels/level.h"
#include "generate/levels/level_one.h"
#include "generate/levels/level_two.h"
#include "generate/field_generator.h"
#include "saving/caretaker/caretaker.h"
#include "saving/caretaker/file_saver.h"
class Game: public Tracked_Object
{
    private:
        bool play;
        bool menu_play;
        bool load = false;
        Observer* observer;
        Input* controller;
        Field* field = nullptr;
        View* view;
        Mediator* mediator;
        Player* player = nullptr;
        Event_Mediator* event_mediator;
        Menu_View* menu_view;
        Field* Choose_Level(int level,Observer* observer, int width, int height);
        Level* level_generator;
        Caretaker* caretaker = nullptr;
        File_Saver* file_saver;
    public:
        Game();
        void Menu();
        void Menu_Exit();
        void Game_Process();
        void Game_Exit();
        void Save();
        void Do_Load();
        void Load();
        //void Menu_Load();
        ~Game();
};
#endif