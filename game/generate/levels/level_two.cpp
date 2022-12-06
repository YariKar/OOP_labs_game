#include "level_two.h"
#include "../../logging/observer.h"
#include "level.h"
Field* Level_Two::Generate_Level(Observer* observer,int width, int height)
{
    using pl_pos = Player_Pos<true>;
    using lab_way = Way_Generate<true>;
    using event_num = Event_Num<0>;
    using event_chance = Event_Chance<0,0,0,0>;
    using event_place = Event_Place<true>;
    //using exit_pos = Exit_Pos<true>;
    using wall_chance = Wall_Chance<35>;
    Field_Generator<wall_chance,lab_way,pl_pos,event_num,event_chance,event_place> generator;

    return generator.Generate_Field(observer,width,height);
}