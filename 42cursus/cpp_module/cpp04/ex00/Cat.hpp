#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal{
public:
	Cat(void);
	Cat(const Cat& obj);
	Cat& operator= (const Cat& obj);
	~Cat(void);
	void makeSound(void) const;
};

#endif