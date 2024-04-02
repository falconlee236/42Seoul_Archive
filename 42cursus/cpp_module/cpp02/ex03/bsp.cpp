#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point){
    bool	sign[3];
	sign[0] = ((point.get_x() - a.get_x()) * (b.get_y() - a.get_y()) - 
        (b.get_x() - a.get_x()) * (point.get_y() - a.get_y())) > 0;
	sign[1] = ((point.get_x() - b.get_x()) * (c.get_y() - b.get_y()) - 
        (c.get_x() - b.get_x()) * (point.get_y() - b.get_y())) > 0;
	sign[2] = ((point.get_x() - c.get_x()) * (a.get_y() - c.get_y()) -
        (a.get_x() - c.get_x()) * (point.get_y() - c.get_y())) > 0;
    return sign[0] == sign[1] && sign[1] == sign[2];
}