#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
//#include "../player/player.h"
#include "../logging/tracked_object.h"
#include "../saving/saved_object.h"
#include "../saving/memento/memento.h"
#include "../saving/memento/field_memento.h"
#define COUNT_EVENT_TYPE 4
class Player;
class Field :public Tracked_Object::Tracked_Object, public Saved_Object
{
    private:
        Cell*** field; //save walls coords
        int player_x = 0; //save
        int player_y = 0; //save

        int field_height; //save
        int field_width;  //save
        int rec_counter = 0;
        bool is_walls = true; //save
        bool PossMove(int x,int y);
        bool IsWinPossible(int i,int j);
        
        int win_cell_x; //save
        int win_cell_y; //save

        int event_count = 0;
        int* event_chance = nullptr;
        int wall_chance = 20;

        void RandEventType(int y,int x);
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
        void RandPl();
        void RandWin();
        void RandField(int x, int y);
        void RandEventCoords();
        void SetEventCount(int count);
        void SetEventChance(int* chances);
        void SetWallChance(int chance);
        Field_Memento* save();
        void load(Field_Memento* memento);
        //void Notify(int level,std::string mes);
};
#endif