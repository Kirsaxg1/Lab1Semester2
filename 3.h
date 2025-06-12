#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
#include <stdexcept>

class complex final {

    double _real_part;
    double _imaginary_part;

public:

    complex(double real_part = 0, double imaginary_part = 0);
    ~complex() = default;
    complex(const complex& other) = default;

    complex& operator=(const complex& other) = default;

    complex operator+(const complex& other) const;
    complex& operator+=(const complex& other)&;

    complex operator-(const complex& other) const;
    complex& operator-=(const complex& other)&;

    complex operator*(const complex& other) const;
    complex& operator*=(const complex& other)&;

    complex operator/(const complex& other) const;
    complex& operator/=(const complex& other)&;

    complex module() const;
    complex arg() const; 

    friend std::ostream& operator<<(std::ostream& out, const complex& number);// оператор вставки и выгрузки в поток
    friend std::istream& operator>>(std::istream& in, complex& number);


};

#endif // COMPLEX_H
