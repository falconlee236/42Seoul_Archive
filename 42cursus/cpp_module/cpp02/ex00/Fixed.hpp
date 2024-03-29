#ifndef __FIXED_HPP__
#define __FIXED_HPP__
#include <iostream>

class Fixed{
private:
    int value;
    static const int frac_bit = 8;
public:
    //default constructor
    Fixed();
    // copy constructor
    Fixed(const Fixed& fixed);
    // copy assignment operator overload
    Fixed& operator= (const Fixed& fixed);
    //destructor
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
#endif
