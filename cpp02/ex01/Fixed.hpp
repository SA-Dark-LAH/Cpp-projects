#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // not needed in header but harmless

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    // Orthodox Canonical Form
    Fixed();                        // default
    Fixed(const Fixed &other);      // copy
    Fixed& operator=(const Fixed &other); // copy assign
    ~Fixed();

    // new constructors (ex01)
    Fixed(const int n);             // int -> fixed
    Fixed(const float f);           // float -> fixed

    // getters / converters
    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int   toInt(void) const;
};

// non-member operator<<
std::ostream &operator << (std::ostream &output, const Fixed &f);

#endif
