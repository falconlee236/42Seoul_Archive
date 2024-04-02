#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}
Point::Point(const float _x, const float _y) : x(_x), y(_y) {}
Point::Point(const Point& ref) : x(ref.get_x()), y(ref.get_y()){}
Point& Point::operator= (const Point& ref){
    if (this != &ref){
        const_cast<Fixed &>(this->x) = ref.get_x();
        const_cast<Fixed &>(this->y) = ref.get_y();
    }
    return *this;
}
Point::~Point(void){};
Fixed Point::get_x(void) const { return this->x; }
Fixed Point::get_y(void) const { return this->y; }