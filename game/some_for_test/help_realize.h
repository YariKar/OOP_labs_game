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