#include "../incl.h"
#include "controller.h"
        bool Controller::IsSucsessSize()
            {
                if (Controller::field_height >=5 && Controller::field_height<=14 && Controller::field_width>=5 && Controller::field_width<=14)
                    return true;
                return false;
            }
        bool Controller::IsSucsessLog(bool log)
        {
            return (log==0 || log == 1);
        }
        Controller::Controller(Observer* observer)
        {
            Tracked_Object::SetObserver(observer);
            std::map<std::string, bool> logs {{"file",0}, {"console",0}};
            std::map<std::string, bool> level {{"info",0},{"game",0},{"error",0}};
            std::cout<<"Выберите уровни логгирования.\n";
            std::cout<<"Записывать логи в файл? (0/1)\n";
            std::cin>>logs["file"];
            if(std::cin.fail()|| !IsSucsessLog(logs["file"]))
                {
                    std::cin.clear();
                    std::cin.ignore();
                }
            std::cout<<"Записывать логи в консоль? (0/1)\n";
            std::cin>>logs["console"];
            if(std::cin.fail()|| !IsSucsessLog(logs["console"]))
                {
                    std::cin.clear();
                    std::cin.ignore();
                }
            if(logs["file"] || logs["console"])
            {
                std::cout<<"Записывать логи 1 уровня (состояния игрока и поля, события) (0/1)\n";
                std::cin>>level["info"];
                if(std::cin.fail()|| !IsSucsessLog(level["info"]))
                {
                    std::cin.clear();
                    std::cin.ignore();
                }
                std::cout<<"Записывать логи 2 уровня (состояния игры) (0/1)\n";
                std::cin>>level["game"];
                if(std::cin.fail()|| !IsSucsessLog(level["game"]))
                {
                    std::cin.clear();
                    std::cin.ignore();
                }
                std::cout<<"Записывать логи 3 уровня (критические состояния) (0/1)\n";
                std::cin>>level["error"];
                if(std::cin.fail()|| !IsSucsessLog(level["error"]))
                {
                    std::cin.clear();
                    std::cin.ignore();
                }
            }
            //std::cout<<logs["file"]<<' '<<logs["console"]<<' '<<level["info"]<<' '<<level["game"]<<' '<<level["error"]<<'\n';
            Tracked_Object::GetObserver()->Set_Logs_Level(logs,level);
        }
        void Controller::PutFieldSize()
        {
            bool succsess_inp = false;
            std::cout<<"Добро пожаловать. Перед началом игры введите, пожалуйста, размеры поля в клетках.\nВведите значения через пробел. Диапазон значений от 5*5 до 14*14\n";
            while (succsess_inp != true)
            {
                std::cin>>Controller::field_width>>Controller::field_height;
                if(std::cin.fail()|| IsSucsessSize() == false)
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::system("clear");
                    Tracked_Object::Notify("error","Попытка ввести некорректные размеры поля");
                    std::cout<<"Ошибка ввода. Пожалуйста, введите данные повторно. Вводите значения через пробел. Диапазон значений от 5*5 до 14*14\n";
                }
                else
                    succsess_inp = true;
            }
            Tracked_Object::Notify("game","Размеры поля успешно заданы");
            //std::system("clear");

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
