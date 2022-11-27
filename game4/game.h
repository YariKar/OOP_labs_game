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
class Game: public Tracked_Object
{
    private:
        bool play;
        bool menu_play;
        Observer* observer;
        Input* controller;
        Field* field;
        View* view;
        Mediator* mediator;
        Player* player;
        Event_Mediator* event_mediator;
        Menu_View* menu_view;
    public:
        Game();
        void Menu();
        void Menu_Exit();
        void Game_Process();
        void Game_Exit();
        ~Game();
};
#endif