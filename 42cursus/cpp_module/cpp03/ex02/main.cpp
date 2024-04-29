#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
    std::cout << "### CLAPTRAP ###\n\b";{
        std::cout << "\033[34mConstructing\033[0m" << std::endl;
        ClapTrap a;
        ClapTrap b("Clap");

        std::cout << "\033[34mTesting\033[0m" << std::endl;
        a.attack("some other robot");
        a.takeDamage(10);
        a.takeDamage(10);
        a.beRepaired(5);
        a.attack("some other other robot");
        b.beRepaired(3);
        for (int i = 0; i < 12; i++)
            b.attack("Cody-clone");
        b.beRepaired(3);
        std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
    }
    std::cout << "\n\n### SCAVTRAP ###\n\n";{
        std::cout << "\033[34mConstructing\033[0m" << std::endl;
        ScavTrap c;
        ScavTrap d("Scav");

        std::cout << "\033[34mTesting\033[0m" << std::endl;
        c.attack("CloneTrap");
        c.beRepaired(22);
        c.takeDamage(21);
        c.beRepaired(22);
        c.guardGate();
        c.guardGate();
        d.attack("Savage-clone");
        d.takeDamage(101);
        d.takeDamage(15);
        d.attack("ScavTrap-clone");
        std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
    }
    std::cout << "\n\n FRAGTRAP ###\n\n";{
        std::cout << "\033[34mConstructing\033[0m" << std::endl;
        FragTrap e;
        FragTrap f("Frag");

        std::cout << "\033[34mTesting\033[0m" << std::endl;
        e.highFiveGuys();
        e.attack("some random dude");
        e.takeDamage(101);
        e.takeDamage(1);
        e.attack("some random dude");
        f.highFiveGuys();
        std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
    }
}