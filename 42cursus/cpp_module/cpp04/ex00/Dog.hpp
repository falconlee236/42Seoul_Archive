#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal{
public:
	Dog(void);
	Dog(const Dog& obj);
	Dog& operator= (const Dog& obj);
	~Dog(void);
	void makeSound(void) const;
};

#endif