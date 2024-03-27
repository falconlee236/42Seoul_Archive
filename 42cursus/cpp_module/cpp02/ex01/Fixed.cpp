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
    return this->value;
}
void Fixed::setRawBits(int const raw){
    this->value = raw;
}

//ex01
Fixed::Fixed(const int value){
    std::cout << "Int constructor called\n";
    this->value = value << this->frac_bit;
}

Fixed::Fixed(const float value){
    std::cout << "Float constructor called\n";
    this->value = roundf(value * (1 << this->frac_bit));
}

int Fixed::toInt(void) const {
    return (this->value >> this->frac_bit);
}

float Fixed::toFloat(void) const{
    return ((float)this->value / (1 << this->frac_bit));
}
// insertion operator overload
std::ostream& operator<< (std::ostream& os, const Fixed& fixed){
    os << fixed.toFloat();
    return os;
}