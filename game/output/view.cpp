#include "../incl.h"
#include "view.h"

        View::View(int field_width, int field_height)
        {
            View::field_height = field_height;
            View::field_width = field_width;
        }
        void View::DrawWindow(Field* field)
        {
            for (int i = 0; i < View::field_height;i++)
            {
                //DrawCellLine(i);
                for (int j = 0;j<View::cell_height;j++)
                {
                    //DrawLine(line);
                    for(int k = 0;k<View::field_width;k++)
                    {
                        for(int l = 0;l<View::cell_width;l++)
                        {
                            //std::cout<<i<<' '<<k<<' '<<field->GetField()[i][k]->GetPossability()<<'\n';
                            if (!(field->GetField()[i][k]->GetExplore()))
                            {
                                std::cout<<'?';
                                continue;
                            }
                            /*else
                            {*/
                            if (field->GetPlX()==k && field->GetPlY()==i)
                            {
                                std::cout<<'p';
                                continue;
                            }
                            if (field->GetField()[i][k]->GetPossability() == false)
                            {
                                std::cout<<'#';
                                continue;
                            }
                                    //else
                            
                            if (field->GetWinX()==k && field->GetWinY()==i)
                            {
                                std::cout<<'w';
                                continue;
                            }
                            if (field->GetField()[i][k]->IsEvent())
                            {
                                std::cout<<'e';
                                continue;
                            }
                            else
                            {
                                std::cout<<'*';
                                continue;
                            }
                            //}
                        }
                        std::cout<<' ';
                    }
                    std::cout<<'\n';
                }
                std::cout<<'\n';
            }
        }
        void View::DrawStats(Player* player)
        {
            std::cout<<"energy = "<<player->GetEnergy()<<'/'<<player->GetMaxEnergy()<<'\n';
            /*if(player->GetOffWallMode())
                std::cout<<"without wall mode on\n";
            else
                std::cout<<"without wall mode off\n";*/
            if(player->GetBlindMode())
                std::cout<<"blind mode on\n";
            else
                std::cout<<"blind mode off\n";
        }