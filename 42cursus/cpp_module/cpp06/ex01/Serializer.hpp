#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <iostream>

struct Data{
    std::string name;
};

class Serializer{
private:
    Serializer(void);
public:
    Serializer(const Serializer& obj);
    Serializer &operator=(const Serializer& obj);
    ~Serializer(void);
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif