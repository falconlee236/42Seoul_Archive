#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{
private:
	Brain* brain;
public:
	Cat(void);
	Cat(const Cat& obj);
	Cat& operator= (const Cat& obj);
	~Cat(void);
	void makeSound(void) const;
	Brain* getBrain(void) const;
};

#endif