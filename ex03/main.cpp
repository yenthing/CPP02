
#include "Point.hpp"

int main(void)
{
    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(3), Fixed(0));
    Point c(Fixed(0), Fixed(3));
    Point point(Fixed(1), Fixed(1));
    std::cout << "Point is inside the triangle: " << std::boolalpha << bsp(a, b, c, point) << std::endl;
    return 0;
}
