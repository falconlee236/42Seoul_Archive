#include "FragTrap.hpp"

FragTrap::FragTrap(void){
    this->_name = "default";
    this->_hit = 100;
    this->_energy = 100;
    this->_attack = 30;
    std::cout << "FragTrap " << this->_name << " constructor called\n";
}

FragTrap::FragTrap(std::string name){
    this->_name = name;
    this->_hit = 100;
    this->_energy = 100;
    this->_attack = 30;
    std::cout << "FragTrap " << this->_name << " constructor called\n";
}

FragTrap::FragTrap(const FragTrap &ref){
    this->_name = ref._name;
    this->_hit = ref._hit;
    this->_energy = ref._energy;
    this->_attack = ref._attack;
    std::cout << "FragTrap " << this->_name << " copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &ref){
    if (this != &ref)
    {
        this->_name = ref._name;
        this->_hit = ref._hit;
        this->_energy = ref._energy;
        this->_attack = ref._attack;
    }
    std::cout << "FragTrap " << this->_name << " operator = called\n";
    return *this;
}

FragTrap::~FragTrap(void){
    std::cout << "FragTrap " << this->_name << " destructor called\n";
}

void FragTrap::highFiveGuys(void){
    if (this->_energy == 0 || this->_hit == 0){
        std::cout << "FragTrap " << this->_name << " cannot do anything\n";
    }
    else{
        std::cout << "FragTrap " << this->_name << " displays a high fives request\n";
    }
}