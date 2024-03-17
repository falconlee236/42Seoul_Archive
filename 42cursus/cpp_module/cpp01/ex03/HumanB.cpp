#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    this->_name = name;
}

void HumanB::attack(void){
    std::cout << this->_name << " attacks with their " << (this->_weapon->getType()) << "\n";
}

void HumanB::setWeapon(Weapon &weapon){
    this->_weapon = &weapon;
}