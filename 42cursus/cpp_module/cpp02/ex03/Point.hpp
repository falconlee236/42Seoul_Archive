#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point{
private:
    const Fixed x;
    const Fixed y;
public:
    Point(void);
    Point(const float x, const float y);
    Point(const Point& ref);
    Point& operator= (const Point& ref);
    ~Point(void);
    Fixed get_x(void) const;
    Fixed get_y(void) const;
};

const Point operator- (const Point& a, const Point& b);

#endif