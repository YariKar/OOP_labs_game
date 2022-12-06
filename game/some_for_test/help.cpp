#include <iostream>
#include <string>
/*class Observer{
    std::string message = "Сообщение из наблюдателя";
};

class Log_Console_First
{
    private:
        std::string message = "Сообщение для вывода\n";
    public:
       friend std::ostream& operator<<(std::ostream& out,const  Log_Console_First& obj)
        {
            const std::string prefix = "lcf_";
            out << (prefix + obj.message);
            return out;
        }
};*/
/*template<typename T>
class Command_Reader
{
    private:
        T input;
    public:
        Command_Reader(T input)
        {
            this->input = input;
        }
        void print()
        {
            std::cout<<input<<'\n';
        }
};*/
#include "help.h"
template <typename T>
Command_Reader<T>::Command_Reader(T input)
        {
            this->input = input;
        }

template <typename T>
void Command_Reader<T>::print()
        {
            std::cout<<input<<'\n';
        }

/*int main()
{
    Command_Reader<int> cr(10);
    cr.print();
    return 0;
}*/