#include "Fixed.hpp"

Fixed::Fixed(){
    this->value = 0;
}

Fixed::Fixed(const Fixed& fixed){
    this->value = fixed.getRawBits();
}

Fixed& Fixed::operator= (const Fixed& fixed){
    if (this != &fixed){
        this->value = fixed.getRawBits();
    }
    return (*this);
}
Fixed::~Fixed(){

}
int Fixed::getRawBits(void) const {
    return this->value;
}
void Fixed::setRawBits(int const raw){
    this->value = raw;
}

//ex01
Fixed::Fixed(const int value){
    this->value = value << this->frac_bit;
}

Fixed::Fixed(const float value){
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
bool Fixed::operator> (const Fixed& fixed) const {
    return this->getRawBits() > fixed.getRawBits();
}
bool Fixed::operator< (const Fixed& fixed) const {
    return this->getRawBits() < fixed.getRawBits();
}
bool Fixed::operator>= (const Fixed& fixed) const {
    return this->getRawBits() >= fixed.getRawBits();
}
bool Fixed::operator<= (const Fixed& fixed) const {
    return this->getRawBits() <= fixed.getRawBits();
}
bool Fixed::operator== (const Fixed& fixed) const {
    return this->getRawBits() == fixed.getRawBits();
}
//밖에 const를 붙이는 이유는 왼쪽 연산자또한 const로 받기 위해서 
bool Fixed::operator!= (const Fixed& fixed) const {
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
    const Fixed tmp(*this);

    this->value++;
    return tmp;
}
const Fixed Fixed::operator-- (int){
    const Fixed tmp(*this);

    this->value--;
    return tmp;
}

Fixed& Fixed::max(Fixed& first, Fixed& second){
    return (first > second ? first : second);
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second){
    return (first > second ? first : second);
}
Fixed& Fixed::min(Fixed& first, Fixed& second){
    return (first < second ? first : second);
}
const Fixed& Fixed::min(const Fixed& first, const Fixed& second){
    return (first < second ? first : second);
}