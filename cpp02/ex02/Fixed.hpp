#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 _value;                 // Raw fixed-point value
    static const int    _fractionalBits = 8;    // Number of fractional bits (scale = 256)

public:

    // Orthodox Canonical Form
    Fixed();                                    // Default
    Fixed(const Fixed &other);                  // Copy constructor
    Fixed& operator=(const Fixed &other);       // Copy assignment
    ~Fixed();                                   // Destructor


    //Constructors for ex01
    Fixed(const int n);                         // Convert int -> fixed
    Fixed(const float f);                       // Convert float -> fixed


    int   getRawBits(void) const;
    void  setRawBits(int const raw);


    // Conversions

    float toFloat(void) const;
    int   toInt(void) const;


    // ex02: Comparison operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;


    //ex02: Arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;


    // ex02: Increment / decrement
    Fixed& operator++();       // prefix ++x
    Fixed  operator++(int);    // postfix x++
    Fixed& operator--();       // prefix --x
    Fixed  operator--(int);    // postfix x--


    // ex02: Static min/max
    static Fixed&        min(Fixed &a, Fixed &b);
    static const Fixed&  min(const Fixed &a, const Fixed &b);
    static Fixed&        max(Fixed &a, Fixed &b);
    static const Fixed&  max(const Fixed &a, const Fixed &b);
};


//Stream insertion operator (for cout << obj)
std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif
