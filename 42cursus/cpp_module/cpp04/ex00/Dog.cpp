#include "Dog.hpp"

Dog::Dog(void){
	Animal::type = "Dog";
	std::cout << "Dog default constructor called\n";
}
Dog::Dog(const Dog& obj){
	Animal::type = obj.type;
	std::cout << "Dog copy constructor called\n";
}
Dog& Dog::operator= (const Dog& obj){
	if (this != &obj){
		Animal::type = obj.type;
	}
	std::cout << "Dog operator = called\n";
	return *this;
}
Dog::~Dog(void){
	std::cout << "Dog destructor called\n";
}
void Dog::makeSound(void) const {
	std::cout << "Dog says bark bark!!\n";
}