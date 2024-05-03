#include "Animal.hpp"

Animal::Animal(void){
	this->type = "Animal";
	std::cout << "Animal default constructor called\n";
}
Animal::Animal(const Animal& obj){
	this->type = obj.type;
	std::cout << "Animal copy constructor called\n";
}
Animal& Animal::operator= (const Animal& obj){
	if (this != &obj){
		this->type = obj.type;
	}
	std::cout << "Animal operator = called\n";
	return *this;
}
Animal::~Animal(void){
	std::cout << "Animal destructor called\n";
}
void Animal::makeSound(void) const{
	std::cout << "Animal dosen't say nothing!\n";
}
std::string Animal::getType(void) const{
	return this->type;
}

void Animal::printAddress( void ) const{
	std::cout << "Address: " << this << "\n";
}