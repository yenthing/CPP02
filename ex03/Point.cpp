#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Point::~Point() {}

Point &Point::operator=(const Point &point)
{
    if (this != &point)
    {
        ( Fixed )this->_x = point._x;
        ( Fixed )this->_y = point._y;
    }
    return *this;
}

Fixed Point::getX(void) const
{
    return this->_x;
}

Fixed Point::getY(void) const
{
    return this->_y;
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
    out << "Point(" << point.getX() << ", " << point.getY() << ")";
    return out;
}
