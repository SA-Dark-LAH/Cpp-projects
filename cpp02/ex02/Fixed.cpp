#include "Fixed.hpp"


// Orthodox Canonical Form


Fixed::Fixed() : _value(0)
{
    // No print required by subject in ex02
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;      // Reuse assignment operator
}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_value = other._value;
    return *this;
}

Fixed::~Fixed()
{
    // Nothing special to do
}


// ex01 Constructors


Fixed::Fixed(const int n)
{
    // Integer is shifted to the left by fractional bits (scale = 256)
    _value = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
    // Multiply by scale and round to nearest integer
    _value = (int)roundf(f * (1 << _fractionalBits));
}


int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}


// Conversions

float Fixed::toFloat(void) const
{
    return (float)_value / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;
}

/* ************************************************************
**  ex02: Comparison operators
**
**  Compare raw values directly because scaling is identical.
************************************************************ */

bool Fixed::operator>(const Fixed &o) const { return _value > o._value; }
bool Fixed::operator<(const Fixed &o) const { return _value < o._value; }
bool Fixed::operator>=(const Fixed &o) const { return _value >= o._value; }
bool Fixed::operator<=(const Fixed &o) const { return _value <= o._value; }
bool Fixed::operator==(const Fixed &o) const { return _value == o._value; }
bool Fixed::operator!=(const Fixed &o) const { return _value != o._value; }

/* ************************************************************
**  ex02: Arithmetic operators
**
**  Convert to float, operate, convert back to fixed.
************************************************************ */

Fixed Fixed::operator+(const Fixed &o) const
{
    return Fixed(this->toFloat() + o.toFloat());
}

Fixed Fixed::operator-(const Fixed &o) const
{
    return Fixed(this->toFloat() - o.toFloat());
}

Fixed Fixed::operator*(const Fixed &o) const
{
    return Fixed(this->toFloat() * o.toFloat());
}

Fixed Fixed::operator/(const Fixed &o) const
{
    // Division by zero not required to handle by subject
    return Fixed(this->toFloat() / o.toFloat());
}

/* ************************************************************
**  ex02: Increment / decrement
**
**  One raw unit = smallest representable step (1/256).
**
**  prefix: modify first, return reference
**  postfix: save old value, modify, return old (copy)
************************************************************ */

Fixed& Fixed::operator++()
{
    _value++;
    return *this;       // Return updated object
}

Fixed Fixed::operator++(int)
{
    Fixed old(*this);   // Old value saved via copy constructor
    _value++;           // Modify current object
    return old;         // Return old value by copy
}

Fixed& Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old(*this);
    _value--;
    return old;
}

/* ************************************************************
**  ex02: Static min/max
**
**  Two versions of each: (non-const, const)
**  Required by subject to keep const-correctness.
************************************************************ */

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

/* ************************************************************
**  operator<<
**
**  Print the fixed value as a float.
************************************************************ */

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
    os << f.toFloat();
    return os;
}
