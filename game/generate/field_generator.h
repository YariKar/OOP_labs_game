#pragma once
#include "../incl.h"
#include "../field/field.h"
#include "../logging/observer.h"

#include "concreate_rules/player_pos.h"
#include "concreate_rules/way_generate.h"
#include "concreate_rules/event_num.h"
#include "concreate_rules/event_chance.h"
#include "concreate_rules/event_place.h"
#include "concreate_rules/exit_pos.h"
#include "concreate_rules/wall_chance.h"
template<typename ... Rules>
class Field_Generator
{
    public:
        Field* Generate_Field(Observer* observer,int width, int height);

        template<typename RuleType>
        void RuleDefine(Field* field);
};

template<typename ... Rules>
Field* Field_Generator<Rules ...>::Generate_Field(Observer* observer, int height, int width)
{
    Field* field = new Field(observer,width,height);
    (RuleDefine<Rules>(field), ...);
    field->RandWin();
    return field;
}

template <typename ... Rules>
template <typename RuleType>
void Field_Generator<Rules ...>::RuleDefine(Field* field)
{
    RuleType rule_obj;
    rule_obj.declare(field);
}