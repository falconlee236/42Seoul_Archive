#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <iostream>

class WrongAnimal{
protected:
	std::string type;
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& obj);
	WrongAnimal& operator= (const WrongAnimal& obj);
	~WrongAnimal(void);
	void makeSound(void) const;
	std::string getType(void) const;
};

#endif