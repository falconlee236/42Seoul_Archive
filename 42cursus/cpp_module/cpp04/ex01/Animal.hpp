#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal{
protected:
	std::string type;
public:
	Animal(void);
	Animal(const Animal& obj);
	Animal& operator= (const Animal& obj);
	virtual ~Animal(void);
	virtual void makeSound(void) const;
	std::string getType(void) const;
	void printAddress( void ) const;
};

#endif