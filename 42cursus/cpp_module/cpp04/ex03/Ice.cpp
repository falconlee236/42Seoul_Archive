#include "Ice.hpp"

Ice::Ice(void){
	this->_type = "ice";
	std::cout << "Ice Default constructor called\n";
}

Ice::Ice(const Ice& obj){
	this->_type = obj.getType();
	std::cout << "Ice copy constructor called\n";
}

Ice& Ice::operator= (const Ice& obj){
	if (this != &obj)
		this->_type = obj.getType();
	std::cout << "Ice operator = called\n";
    return *this;
}

Ice::~Ice(void){
	std::cout << "Ice destructor called\n";
}

Ice* Ice::clone() const{
	return new Ice();
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}