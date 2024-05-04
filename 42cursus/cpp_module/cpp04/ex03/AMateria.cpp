#include "AMateria.hpp"

AMateria::AMateria(void) : _type("AMateria"){
    std::cout << "Default AMateria constructor called\n";
}

AMateria::AMateria(const AMateria &obj){
    std::cout << "Default AMateria constructor called\n";
}
AMateria& AMateria::operator= (const AMateria &obj){

}
AMateria::~AMateria(void){

}

AMateria::AMateria(std::string const &type){
    
}

std::string const& AMateria::getType() const{

}

void AMateria::use(ICharacter &target){

}