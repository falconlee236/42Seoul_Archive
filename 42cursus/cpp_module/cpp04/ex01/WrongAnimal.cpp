#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal& obj){
	this->type = obj.type;
	std::cout << "WrongAnimal copy constructor called\n";
}
WrongAnimal& WrongAnimal::operator= (const WrongAnimal& obj){
	if (this != &obj){
		this->type = obj.type;
	}
	std::cout << "WrongAnimal operator = called\n";
	return *this;
}
WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal destructor called\n";
}
void WrongAnimal::makeSound(void) const{
	std::cout << "WrongAnimal dosen't say nothing!\n";
}
std::string WrongAnimal::getType(void) const{
	return this->type;
}