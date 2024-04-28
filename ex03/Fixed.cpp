#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    return ;
}

Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}

Fixed::Fixed(const int value)
{
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    _value = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
    return ;
}

int Fixed::getRawBits(void) const
{
    return _value;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    _value = fixed.getRawBits();
    return *this;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    return Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void)
{
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--(void)
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return toFloat() > fixed.toFloat();
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return toFloat() < fixed.toFloat();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return toFloat() >= fixed.toFloat();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return toFloat() <= fixed.toFloat();
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return toFloat() != fixed.toFloat();
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a > b ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a < b ? a : b;
}
