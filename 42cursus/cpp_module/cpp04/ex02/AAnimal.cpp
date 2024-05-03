#include "AAnimal.hpp"

AAnimal::AAnimal(void){
	this->type = "AAnimal";
	std::cout << "AAnimal default constructor called\n";
}
AAnimal::AAnimal(const AAnimal& obj){
	this->type = obj.type;
	std::cout << "AAnimal copy constructor called\n";
}
AAnimal& AAnimal::operator= (const AAnimal& obj){
	if (this != &obj){
		this->type = obj.type;
	}
	std::cout << "AAnimal operator = called\n";
	return *this;
}
AAnimal::~AAnimal(void){
	std::cout << "AAnimal destructor called\n";
}
void AAnimal::makeSound(void) const{
	std::cout << "AAnimal dosen't say nothing!\n";
}
std::string AAnimal::getType(void) const{
	return this->type;
}

void AAnimal::printAddress( void ) const{
	std::cout << "Address: " << this << "\n";
}