#include "Cat.hpp"

Cat::Cat(void){
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called\n";
}
Cat::Cat(const Cat& obj){
	this->type = obj.type;
	this->brain = new Brain(*obj.getBrain());
	std::cout << "Cat copy constructor called\n";
}
Cat& Cat::operator= (const Cat& obj){
	if (this != &obj){
		this->type = obj.type;
		if (this->brain) delete this->brain;
		this->brain = new Brain(*obj.getBrain());
	}
	std::cout << "Cat operator = called\n";
	return *this;
}
Cat::~Cat(void){
	delete this->brain;
	std::cout << "Cat destructor called\n";
}
void Cat::makeSound(void) const{
	std::cout << "Cat says meow!!\n";
}
Brain* Cat::getBrain(void) const{
	return this->brain;
}