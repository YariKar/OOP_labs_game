#ifndef CELL_H
#define CELL_H
#include "field.h"
#include "../events/event.h"
class Cell
{
    private:
        const int cell_height = 2;
        const int cell_width = 3;
        int pos_x;
        int pos_y;
        bool check_passability;
        bool passabilty;
        bool explore;
        bool true_passability;
        Event* event = nullptr;
        bool is_event = false;
    public:
        Cell(int i, int j);
        ~Cell();
        //bool IsPlayer();
        bool GetPossability();
        void SetTruePossability();
        bool GetCheckPossability();
        void CheckPossability();
        Cell (const Cell& obj);
        Cell& operator=(const Cell& obj);
        void Exploring();
        void NotExploring();
        bool GetExplore();
        void WithoutWall();
        void WithWall();
        void SetEvent(int event_num);
        bool IsEvent();
        Event* GetEvent();
        void DestroyEvent();
};
#endif