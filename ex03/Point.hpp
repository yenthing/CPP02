#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(const Fixed x, const Fixed y);
        Point(const Point &point);
        ~Point();
        Point &operator=(const Point &point);
        Fixed getX(void) const;
        Fixed getY(void) const;
};

std::ostream &operator<<(std::ostream &out, const Point &point);
bool bsp( Point const a, Point const b, Point const c, Point const point);
