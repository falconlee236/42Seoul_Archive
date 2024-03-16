#include "Zombie.hpp"

Zombie::~Zombie(){
    std::cout << this->name << ": is died\n";
}

void Zombie::announce(void){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::set_name(std::string name){
    this->name = name;
}

