#include <iostream>

class ClapTrap{
private:
    std::string _name;
    unsigned int _hit;
    unsigned int _energy;
    unsigned int _attack;
public:
    //default constructor
    ClapTrap(void);
    ClapTrap(std::string name);
    //copy constructor
    ClapTrap(const ClapTrap& ref);
    //copy assignment operator overload
    ClapTrap& operator= (const ClapTrap& ref);
    //destructor
    ~ClapTrap(void);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
