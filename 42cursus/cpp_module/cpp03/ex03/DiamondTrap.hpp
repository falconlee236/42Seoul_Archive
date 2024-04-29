#ifndef __DIAMOND_TRAP_HPP__
#define __DIAMOND_TRAP_HPP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
private:
    std::string _name;

public:
    DiamondTrap(void);
    DiamondTrap(std::string name);
    ~DiamondTrap(void);
    DiamondTrap(const DiamondTrap& ref);
    DiamondTrap& operator= (const DiamondTrap& ref);
    void whoAmI(void);
};

#endif
