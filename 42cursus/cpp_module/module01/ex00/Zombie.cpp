#include "Zombie.hpp"

void announce(void);

Zombie::Zombie(std::string name){
    this->name = name;
}

Zombie::~Zombie(){
    std::cout << this->name << ": is died\n";
}

void Zombie::announce(void){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

