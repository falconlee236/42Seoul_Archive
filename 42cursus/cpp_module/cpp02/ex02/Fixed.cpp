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

//ANCHOR - ex02
bool Fixed::operator> (const Fixed& fixed){
    return this->getRawBits() > fixed.getRawBits();
}
bool Fixed::operator< (const Fixed& fixed){
    return this->getRawBits() < fixed.getRawBits();
}
bool Fixed::operator>= (const Fixed& fixed){
    return this->getRawBits() >= fixed.getRawBits();
}
bool Fixed::operator<= (const Fixed& fixed){
    return this->getRawBits() <= fixed.getRawBits();
}
bool Fixed::operator== (const Fixed& fixed){
    return this->getRawBits() == fixed.getRawBits();
}
bool Fixed::operator!= (const Fixed& fixed){
    return this->getRawBits() != fixed.getRawBits();
}

const Fixed Fixed::operator+ (const Fixed& fixed) const{
    return Fixed(this->toFloat() + fixed.toFloat());
}
const Fixed Fixed::operator- (const Fixed& fixed) const{
    return Fixed(this->toFloat() - fixed.toFloat());
}
const Fixed Fixed::operator* (const Fixed& fixed) const{
    return Fixed(this->toFloat() * fixed.toFloat());
}
const Fixed Fixed::operator/ (const Fixed& fixed) const{
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator++ (void){
    this->value++;
    return (*this);
}
Fixed& Fixed::operator-- (void){
    this->value--;
    return (*this);
}
const Fixed Fixed::operator++ (int){
    return Fixed(this->value + 1);
}
const Fixed Fixed::operator-- (int){
    return Fixed(this->value - 1);
}

static Fixed& max(Fixed& first, Fixed& second){
    
}
static Fixed& max(const Fixed& first, const Fixed& second);
static Fixed& min(Fixed& first, Fixed& second);
static Fixed& min(const Fixed& first, const Fixed& second);