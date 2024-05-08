#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template <typename T>
void iter(T* array, int len, void (*f)(T&)){
    for(int i = 0; i < len; i++){
        f(array[i]);
    }
}

template <typename T>
void print(T& element){
    std::cout << element << std::endl;
}

#endif