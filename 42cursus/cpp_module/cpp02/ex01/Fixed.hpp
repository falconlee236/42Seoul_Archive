#ifndef __FIXED_HPP__
#define __FIXED_HPP__
#include <iostream>

class Fixed{
private:
    int value;
    static const int frac_bit = 8;
public:
    //default constructor
    Fixed(); //ex00
    //const integer constructor
    Fixed(const int value); //ex01
    //const float constructor
    Fixed(const float value); //ex01
    // copy constructor
    Fixed(const Fixed& fixed); //ex00
    // copy assignment operator overload
    Fixed& operator= (const Fixed& fixed); //ex00
    //destructor
    ~Fixed(); //ex00

    int getRawBits(void) const; //ex00
    void setRawBits(int const raw); //ex00
    float toFloat(void) const; //ex01
    int toInt(void) const; //ex01
};
#endif
