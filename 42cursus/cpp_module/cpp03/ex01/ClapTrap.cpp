#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){
    this->_name = "default";
    this->_hit = 10;
    this->_energy = 10;
    this->_attack = 0;
    std::cout << "ClapTrap " << this->_name << " constructor called\n";
}

ClapTrap::ClapTrap(std::string name){
    this->_name = name;
    this->_hit = 10;
    this->_energy = 10;
    this->_attack = 0;
    std::cout << "ClapTrap " << this->_name << " constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& ref){
    this->_name = ref._name;
    this->_hit = ref._hit;
    this->_energy = ref._energy;
    this->_attack = ref._attack;
    std::cout << "ClapTrap " << this->_name << " copy constructor called\n";
}

ClapTrap& ClapTrap::operator= (const ClapTrap& ref){
    if (this != &ref){
        this->_name = ref._name;
        this->_hit = ref._hit;
        this->_energy = ref._energy;
        this->_attack = ref._attack;
    }
    std::cout << "ClapTrap " << this->_name << " operator = called\n";
    return *this;
}

ClapTrap::~ClapTrap(void){
    std::cout << "ClapTrap " << this->_name << " destructor called\n";
}

void ClapTrap::attack(const std::string& target){
    if (this->_energy == 0 || this->_hit == 0){
        std::cout << "ClapTrap " << this->_name << " cannot do anything\n";
    }
    else {
        std::cout << "ClapTrap " << this->_name << " attacks " << target 
            << ", causing " << this->_attack << " points of damage!\n";
        this->_energy--;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->_hit == 0){
        std::cout << "ClapTrap " << this->_name << " is already dead!\n";
        return;
    }
    this->_hit = this->_hit < amount ? 0 : this->_hit - amount;
    std::cout << "ClapTrap " << this->_name << " takeDamage " << amount
              << ", current hit point = " << this->_hit << "\n";
    if (this->_hit == 0){
        std::cout << "ClapTrap " << this->_name << " is dead!\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->_energy == 0 || this->_hit == 0){
        std::cout << "ClapTrap " << this->_name << " cannot do anything\n";
    }
    else{
        this->_hit += amount;
        std::cout << "ClapTrap " << this->_name << " repaired " << amount
                  << ", current hit point = " << this->_hit << "\n";
        this->_energy--;
    }
}