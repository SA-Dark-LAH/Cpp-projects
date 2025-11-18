#include "Fixed.hpp"
#include <cmath> // for roundf

// Default
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment
Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits(); // or other._value
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// int constructor
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = n << _fractionalBits; // multiply by scale
}

// float constructor
Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    this->_value = (int)roundf(f * (1 << _fractionalBits));
}

// raw accessor
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

// conversions
float Fixed::toFloat(void) const {
    return (float)this->_value / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_value >> _fractionalBits;
}

// operator<<
std::ostream &operator << (std::ostream &output, const Fixed &f) {
    output << f.toFloat();
    return output;
}
