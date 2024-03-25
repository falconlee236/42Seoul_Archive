#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called\n";
    this->value = 0;
}

Fixed::Fixed(const Fixed& fixed){
    
}

Fixed& Fixed::operator= (const Fixed& fixed){

}
Fixed::~Fixed(){
}
const int Fixed::getRawBits(void){

}
void Fixed::setRawBits(const int raw){

}