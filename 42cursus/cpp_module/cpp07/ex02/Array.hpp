#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>

template <typename T>
class Array{
private:
    T* arr;
    unsigned int num;
public:
    Array(void){
        this->arr = new T;
        this->num = 0;
    }
    Array(unsigned int n){
        this->arr = new T[n];
        this->num = n;
    }
    Array(const Array& obj){
        this->arr = new T[obj.num];
        this->num = obj.num;
        for(unsigned int i = 0; i < this->num; i++)
            this->arr[i] = obj.arr[i];
    }
    Array &operator =(const Array& obj){
        if (this->arr)
            delete[] this->arr;
        this->arr = new T(obj.num);
        this->num = obj.num;
        for (unsigned int i = 0; i < this->num; i++)
            this->arr[i] = obj.arr[i];
    }
    ~Array(void){
        if (this->arr)
            delete[] this->arr;
    }
    T &operator[](unsigned int idx){
        if (idx < 0 || idx > this->num)
            throw OutOfRange();
        return this->arr[idx];
    }
    const T &operator[](unsigned int idx) const{
        if (idx < 0 || idx > this->num)
            throw OutOfRange();
        return this->arr[idx];
    }
    unsigned int size(void) const{
        return this->num;
    }
    class OutOfRange : public std::exception {
        const char* what() const throw(){
            return "index out of range!";
        }
    };
};


#endif