#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : _name(ClapTrap::_name), ClapTrap(), FragTrap(), ScavTrap(){
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

DiamondTrap::DiamondTrap(const DiamondTrap &ref){
    
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &ref){

}

void DiamondTrap::whoAmI(void){

}