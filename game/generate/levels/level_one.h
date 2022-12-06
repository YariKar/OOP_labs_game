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

class Level_One: public Level
{
    public:
        //Level_One() = default;
        //~Level_One() = default;
        Field* Generate_Level(Observer* observer,int width, int height);
};