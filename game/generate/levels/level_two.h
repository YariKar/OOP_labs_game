#pragma once

#include "level.h"
#include "../../field/field.h"
#include "../concreate_rules/event_chance.h"
#include "../concreate_rules/event_num.h"
#include "../concreate_rules/event_place.h"
#include "../concreate_rules/exit_pos.h"
#include "../concreate_rules/player_pos.h"
#include "../concreate_rules/way_generate.h"
#include "../field_generator.h"
class Level_Two: public Level
{
    public:
        //Level_Two() = default;
        //~Level_Two() = default;
        Field* Generate_Level(Observer* observer,int width, int height);
};