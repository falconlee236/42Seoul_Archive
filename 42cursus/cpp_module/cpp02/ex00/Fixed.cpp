#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called\n";
    this->value = 0;
}

Fixed::Fixed(const Fixed& fixed){
    std::cout << "Copy constructor called\n";
    this->value = fixed.getRawBits();
}

Fixed& Fixed::operator= (const Fixed& fixed){
    std::cout << "Copy assign operator called\n";
    if (this != &fixed){
        this->value = fixed.getRawBits();
    }
    return (*this);
}
Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return this->value;
}
void Fixed::setRawBits(int const raw){
    this->value = raw;
}