#include "Cure.hpp"

Cure::Cure(void){
	this->_type = "cure";
	std::cout << "Cure Default constructor called\n";
}

Cure::Cure(const Cure& obj){
	this->_type = obj.getType();
	std::cout << "Cure copy constructor called\n";
}

Cure& Cure::operator= (const Cure& obj){
	if (this != &obj)
		this->_type = obj.getType();
	std::cout << "Cure operator = called\n";
    return *this;
}

Cure::~Cure(void){
	std::cout << "Cure destructor called\n";
}

Cure* Cure::clone() const{
	return new Cure();
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "\'s wounds *\n";
}