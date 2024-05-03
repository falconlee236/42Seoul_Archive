#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
public:
	WrongCat(void);
	WrongCat(const WrongCat& obj);
	WrongCat& operator= (const WrongCat& obj);
	~WrongCat(void);
	void makeSound(void) const;
};

#endif