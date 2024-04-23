#include <iostream>

class ClapTrap{
private:
    std::string _name;
    int _hit;
    int _energy;
    int _attack;
public:
    //default constructor
    ClapTrap();
    ClapTrap(std::string name);
    //copy constructor
    ClapTrap(const ClapTrap& ref);
    //copy assignment operator overload
    ClapTrap& operator= (const ClapTrap& ref);
    //destructor
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
