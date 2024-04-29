#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){
    this->_name = "default";
    this->_hit = 100;
    this->_energy = 50;
    this->_attack = 20;
    std::cout << "ScavTrap " << this->_name << " constructor called\n";
}

ScavTrap::ScavTrap(std::string name){
    this->_name = name;
    this->_hit = 100;
    this->_energy = 50;
    this->_attack = 20;
    std::cout << "ScavTrap " << this->_name << " constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &ref){
    this->_name = ref._name;
    this->_hit = ref._hit;
    this->_energy = ref._energy;
    this->_attack = ref._attack;
    std::cout << "ScavTrap " << this->_name << " copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ref){
    if (this != &ref){
        this->_name = ref._name;
        this->_hit = ref._hit;
        this->_energy = ref._energy;
        this->_attack = ref._attack;
    }
    std::cout << "ScavTrap " << this->_name << " operator = called\n";
    return *this;
}

ScavTrap::~ScavTrap(void){
    std::cout << "ScavTrap " << this->_name << " destructor called\n";
}

void ScavTrap::attack(const std::string &target){
    if (this->_energy == 0 || this->_hit == 0){
        std::cout << "ScavTrap " << this->_name << " cannot do anything\n";
    }
    else{
        std::cout << "ScavTrap " << this->_name << " attacks " << target
                  << ", causing " << this->_attack << " points of damage!\n";
        this->_energy--;
    }
}

void ScavTrap::guardGate(void){
    std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper Mode\n";
}