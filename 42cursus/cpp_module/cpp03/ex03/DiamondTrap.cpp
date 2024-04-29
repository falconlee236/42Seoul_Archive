#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap(), _name(ClapTrap::_name){
    ClapTrap::_name = this->_name + "_clap_name";
    this->_attack = FragTrap::_attack;
    std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(), FragTrap(), ScavTrap(){
    this->_name = name;
    ClapTrap::_name = this->_name + "_clap_name";
    this->_attack = FragTrap::_attack;
    std::cout << "DiamondTrap " << name << " constructor called\n";
}

DiamondTrap::~DiamondTrap(void){
    std::cout << "DiamondTrap " << this->_name << " destructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref): ClapTrap(ref), FragTrap(ref), ScavTrap(ref){
    this->_attack = FragTrap::_attack;
    std::cout << "DiamondTrap " << this->_name << " copy constructor called\n";
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &ref){
    this->_name = ref._name;
    this->_attack = ref._attack;
    this->_hit = ref._hit;
    this->_energy = ref._energy;
    std::cout << "DiamondTrap operator = " << this->_name << " called\n";
    return (*this);
}

void DiamondTrap::whoAmI(void){
    std::cout << "This DiamondTrap name is " << this->_name
              << " and This ClapTrap name is " << ClapTrap::_name << "\n";
}