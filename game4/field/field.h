#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
//#include "../player/player.h"
#include "../logging/tracked_object.h"
class Player;
class Field :public Tracked_Object::Tracked_Object
{
    private:
        Cell*** field;
        int player_x;
        int player_y;
        int field_height;
        int field_width;
        int rec_counter = 0;
        bool is_walls = true;
        void RandPl();
        void RandWin();
        void RandField(int x, int y);
        void RandEventCoords();
        bool PossMove(int x,int y);
        bool IsWinPossible(int i,int j);
        
        int win_cell_x;
        int win_cell_y;


    public:
        Field(Observer* observer,int field_width, int field_height);
        int GetFieldHeight();
        int GetFieldWidth();
        ~Field();
        Cell*** GetField();
        int GetPlX();
        int GetPlY();
        int GetWinX();
        int GetWinY();
        Field(const Field& obj);
        Field(Field&& obj);
        Field& operator=(const Field& obj);
        Field& operator=(Field&& obj);
        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();
        void OpenCells(Player* player);
        void Recreate_Field(); //собыитие
        void OffWalls(); //событие
        void OnWalls(); 
        bool IsWin();
        bool GetIsWalls();
        //void Notify(int level,std::string mes);
};
#endif