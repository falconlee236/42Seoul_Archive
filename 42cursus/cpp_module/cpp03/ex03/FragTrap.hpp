#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(const FragTrap &ref);
    ~FragTrap(void);
    FragTrap &operator=(const FragTrap &ref);
    void highFiveGuys(void);
};
#endif