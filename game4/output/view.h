#ifndef VIEW_H
#define VIEW_H
#include "../field/field.h"
#include "../player/player.h"
class View
{
    private:
        int field_width;
        int field_height;
        int cell_height =2;
        int cell_width =3;

    public:
        View(int field_width, int field_height);
        void DrawWindow(Field* field);
        void DrawStats(Player* player);
};
#endif