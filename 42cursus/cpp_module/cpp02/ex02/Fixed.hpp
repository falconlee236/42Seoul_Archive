#ifndef __FIXED_HPP__
#define __FIXED_HPP__
#include <iostream>
#include <cmath>

class Fixed{
private:
    int value;
    static const int frac_bit = 8;
public:
    //SECTION - ex00
    Fixed(); //ex00
    Fixed(const Fixed& fixed); //ex00
    ~Fixed(); //ex00
    Fixed& operator= (const Fixed& fixed); //ex00
    int getRawBits(void) const; //ex00
    void setRawBits(int const raw); //ex00
    //!SECTION

    //SECTION - ex01
    Fixed(const int value); //ex01
    Fixed(const float value); //ex01
    float toFloat(void) const; //ex01
    int toInt(void) const; //ex01
    //!SECTION

    //SECTION - ex02
    bool operator> (const Fixed& fixed); //ex02
    bool operator< (const Fixed& fixed); //ex02
    bool operator>= (const Fixed& fixed); //ex02
    bool operator<= (const Fixed& fixed); //ex02
    bool operator== (const Fixed& fixed); //ex02
    bool operator!= (const Fixed& fixed); //ex02

    const Fixed operator+ (const Fixed& fixed) const; //ex02
    const Fixed operator- (const Fixed& fixed) const; //ex02
    const Fixed operator* (const Fixed& fixed) const; //ex02
    const Fixed operator/ (const Fixed& fixed) const; //ex02

    Fixed& operator++ (void);
    Fixed& operator-- (void);
    const Fixed operator++ (int);
    const Fixed operator-- (int);

    static Fixed& max(Fixed& first, Fixed& second);
    static Fixed& max(const Fixed& first, const Fixed& second);
    static Fixed& min(Fixed& first, Fixed& second);
    static Fixed& min(const Fixed& first, const Fixed& second);
    //!SECTION
};

//ANCHOR - ex01
std::ostream& operator<<(std::ostream&os, const Fixed &fixed);
#endif
