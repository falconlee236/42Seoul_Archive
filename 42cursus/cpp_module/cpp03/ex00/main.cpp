#include "ClapTrap.hpp"

int main(void){
    ClapTrap a("A");
    ClapTrap b("B");

    a.attack("B");
    b.takeDamage(5);
    b.beRepaired(3);
    b.attack("A");
    a.takeDamage(10);
    a.beRepaired(10);
    return (0);
}