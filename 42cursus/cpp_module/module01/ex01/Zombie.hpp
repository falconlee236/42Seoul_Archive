#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include <iostream>

class Zombie{
private:
    std::string name;
public:
    ~Zombie();
    void announce(void);
    void set_name(std::string name);
};

Zombie* zombieHorde(int N, std::string name);
#endif