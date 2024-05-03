#include "Dog.hpp"

Dog::Dog(void){
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called\n";
}
Dog::Dog(const Dog& obj){
	this->type = obj.type;
	std::cout << "Dog copy constructor called\n";
}
Dog& Dog::operator= (const Dog& obj){
	if (this != &obj){
		this->type = obj.type;
	}
	std::cout << "Dog operator = called\n";
	return *this;
}
Dog::~Dog(void){
	delete this->brain;
	std::cout << "Dog destructor called\n";
}
void Dog::makeSound(void) const {
	std::cout << "Dog says bark bark!!\n";
}