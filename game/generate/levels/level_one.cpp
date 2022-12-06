#include "level_one.h"
#include "../../logging/observer.h"
#include "level.h"
Field* Level_One::Generate_Level(Observer* observer,int width, int height)
{
    using pl_pos = Player_Pos<true>;
    using lab_way = Way_Generate<true>;
    using event_num = Event_Num<10>;
    using event_chance = Event_Chance<40,40,10,10>;
    using event_place = Event_Place<true>;
    using wall_chance = Wall_Chance<30>;
    Field_Generator<pl_pos,wall_chance,lab_way,event_num,event_chance,event_place> generator; 
    return generator.Generate_Field(observer,width,height);
}