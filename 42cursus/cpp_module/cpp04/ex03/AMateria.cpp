#include "AMateria.hpp"

AMateria::AMateria(void) {
    this->_type = "AMateria";
    std::cout << "AMateria Default constructor called\n";
}

AMateria::AMateria(const AMateria &obj){
    this->_type = obj.getType();
    std::cout << "AMateria copy constructor called\n";
}
AMateria& AMateria::operator= (const AMateria &obj){
    if (this != &obj)
        this->_type = obj.getType();
    std::cout << "AMateria operator = called\n";
    return *this;
}
AMateria::~AMateria(void){
    std::cout << "AMateria destructor called\n";
}

AMateria::AMateria(std::string const &type){
    this->_type = type;
    std::cout << "AMateria type constructor called\n";
}

std::string const& AMateria::getType() const{
    return this->_type;
}

void AMateria::use(ICharacter &target){
    std::cout << "AMateria abstractly used on " << target.getName() << "\n";
}