#include "ScavTrap.hpp"

int main(void){
    {
        ScavTrap* scav = new ScavTrap("scav");

        scav->attack("Handsome Jack");
        scav->takeDamage(6);
        scav->beRepaired(4);
        scav->takeDamage(3);
        scav->guardGate();
        scav->beRepaired(8);
        scav->takeDamage(17);
        delete scav;
    }
    {
        ClapTrap *clap = new ClapTrap("clap");

        clap->attack("Handsome Jack");
        clap->takeDamage(6);
        clap->beRepaired(4);
        clap->takeDamage(3);
        clap->beRepaired(8);
        clap->takeDamage(17);
        delete clap;
    }
}