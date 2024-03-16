#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>

class Weapon{
private:
    std::string type;
public:
    std::string& const getType(void);
    void setType(std::string type);
};
#endif