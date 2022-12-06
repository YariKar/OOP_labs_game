#include "game.h"
class Game;
int main()
{
    Game* game = new Game();
    game->Menu();
    delete game;
    return 0;
}

