#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed const x = point.getX();
    Fixed const y = point.getY();
    Fixed const x1 = a.getX();
    Fixed const y1 = a.getY();
    Fixed const x2 = b.getX();
    Fixed const y2 = b.getY();
    Fixed const x3 = c.getX();
    Fixed const y3 = c.getY();
    Fixed const x1y1_x2y2 = (x1 - x) * (y2 - y1) - (x2 - x1) * (y1 - y);
    Fixed const x2y2_x3y3 = (x2 - x) * (y3 - y2) - (x3 - x2) * (y2 - y);
    Fixed const x3y3_x1y1 = (x3 - x) * (y1 - y3) - (x1 - x3) * (y3 - y);
    return (x1y1_x2y2 >= 0 && x2y2_x3y3 >= 0 && x3y3_x1y1 >= 0) || (x1y1_x2y2 <= 0 && x2y2_x3y3 <= 0 && x3y3_x1y1 <= 0);
}
