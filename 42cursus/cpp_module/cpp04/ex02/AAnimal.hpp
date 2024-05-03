#ifndef __AANIMAL_HPP__
#define __AANIMAL_HPP__

#include <iostream>

class AAnimal{
protected:
	std::string type;
public:
	AAnimal(void);
	AAnimal(const AAnimal& obj);
	AAnimal& operator= (const AAnimal& obj);
	virtual ~AAnimal(void);
	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
	void printAddress( void ) const;
};

#endif