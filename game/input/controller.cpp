#include "../incl.h"
#include "controller.h"
        bool Controller::IsSuccessSize()
            {
                if (Controller::field_height >=5 && Controller::field_height<=14 && Controller::field_width>=5 && Controller::field_width<=14)
                    return true;
                return false;
            }
        Controller::Controller(){}
        void Controller::PutFieldSize()
        {
            bool succsess_inp = false;
            std::cout<<"Добро пожаловать. Перед началом игры введите, пожалуйста, размеры поля в клетках.\nВведите значения через пробел. Диапазон значений от 5*5 до 14*14\n";
            while (succsess_inp != true)
            {
                std::cin>>Controller::field_width>>Controller::field_height;
                if(std::cin.fail()|| IsSuccessSize() == false)
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::system("clear");
                    std::cout<<"Ошибка ввода. Пожалуйста, введите данные повторно. Вводите значения через пробел. Диапазон значений от 5*5 до 14*14\n";
                }
                else
                    succsess_inp = true;
            }
            std::system("clear");
        }
        int Controller::GetFieldWidth()
        {
            return Controller::field_width;
        }
        int Controller::GetFieldHeight()
        {
            return Controller::field_height;
        }
        void Controller::PutMove()
        {
            char inp_symb;
            //inp_symb = getchar();
            std::cin>>inp_symb;
            Controller::direction = inp_symb;
        }
        char Controller::GetDir()
        {
            return Controller::direction;
        }
