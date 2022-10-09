#include "../incl.h"
#include "field.h"
#include "cell.h"
#include "../events/event.h"
#include "../events/blind_trap.h"
#include "../events/eat_energy.h"
#include "../events/recreate_field.h"
#include "../events/off_walls.h"

Cell::Cell(int i,int j)
{
    //srand(time(0));
    passabilty = false;
    true_passability = passabilty;
    check_passability = false;
    pos_x = j;
    pos_y = i;
    explore = false;
}
Cell::~Cell()
{
    if(event)
        delete [] event;
}
bool Cell::GetPossability()
{
    return passabilty;
}
void Cell::SetTruePossability()
{
    passabilty = true;
    true_passability = passabilty;
}
Cell::Cell(const Cell& obj)
{
    pos_x = obj.pos_x;
    pos_y = obj.pos_y;
    passabilty = obj.passabilty;
}
Cell& Cell::operator=(const Cell& obj)
{
        pos_x = obj.pos_x;
        pos_y = obj.pos_y;
        passabilty = obj.passabilty;
    return *this;
}
void Cell::Exploring()
{
    explore = true;
}
void Cell::NotExploring()
{
    explore = false;
}
bool Cell::GetExplore()
{
    return explore;
}
void Cell::WithoutWall()
{
    passabilty = true;
}
void Cell:: WithWall()
{
    //std::cout<<true_passability<<'\n';
    passabilty = true_passability;
}

bool Cell::GetCheckPossability()
{
    return check_passability;
}
void Cell::CheckPossability()
{
    check_passability = true;
}
void Cell::SetEvent(int event_num)
{
    is_event = true;
    switch(event_num)
    {
        case 0:
            event = new Eat_Energy();
            break;
        case 1:
            event = new Blind_Trap();
            break;
        case 2:
            event = new Off_Walls();
            break;
        case 3:
            event = new Recreate_Field();
            break;
    }
}
bool Cell::IsEvent()
{
    /*if (event)
        return true;
    return false;*/
    return is_event;
}
Event* Cell::GetEvent()
{
    return event;
}
void Cell::DestroyEvent()
{
    is_event = false;
}





