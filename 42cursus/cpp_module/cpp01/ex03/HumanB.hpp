#ifndef __HUMANB_H__
#define __HUMANB_H__
#include "Weapon.hpp"

class HumanB{
private:
    Weapon* _weapon;
    std::string _name;
public:
    HumanB(std::string name);
    void attack(void);
    void setWeapon(Weapon &weapon);
};
#endif