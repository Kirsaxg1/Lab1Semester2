#include "3.h"
#include <cmath>
#include <iostream>


#include <stdexcept>

complex::complex(double real_part, double imaginary_part)
    : _real_part(real_part), _imaginary_part(imaginary_part)
{
}

complex& complex::operator+=(const complex& other)&
{
    _real_part += other._real_part;
    _imaginary_part += other._imaginary_part;
    return *this;
}

complex complex::operator+(const complex& other) const
{
    complex result = *this;
    result += other;
    return result;
}

complex& complex::operator-=(const complex& other)&
{
    _real_part -= other._real_part;
    _imaginary_part -= other._imaginary_part;
    return *this;
}

complex complex::operator-(const complex& other) const
{
    complex result = *this;
    result -= other;
    return result;
}

complex& complex::operator*=(const complex& other)&
{
    _real_part = _real_part * other._real_part - _imaginary_part * other._imaginary_part;
    _imaginary_part = _real_part * other._imaginary_part + _imaginary_part * other._real_part;
    return *this;
}

complex complex::operator*(const complex& other) const
{
    complex copy_obj(*this);
    // complex copy = *this;
    return copy_obj += other;

}

complex complex::operator/(const complex& other) const
{
    double denominator = other._real_part * other._real_part +
        other._imaginary_part * other._imaginary_part;

    if (denominator == 0.0)
    {
        throw std::invalid_argument("Division by zero in complex numbers");
    }

    return complex(
        (_real_part * other._real_part + _imaginary_part * other._imaginary_part) / denominator,
        (_imaginary_part * other._real_part - _real_part * other._imaginary_part) / denominator
    );
}


complex& complex::operator/=(const complex& other)&
{
    *this = *this / other;
    return *this;
}

complex complex::module() const
{
    return complex(std::sqrt(_real_part * _real_part + _imaginary_part * _imaginary_part), 0);
}


complex complex::arg() const
{
    return complex(std::atan2(_imaginary_part, _real_part), 0);
}


std::ostream& operator<<(std::ostream& out, const complex& number)
{
    out << number._real_part;

    if (number._imaginary_part >= 0)
    {
        out << " + " << number._imaginary_part << "i";
    }
    else
    {
        out << " - " << -number._imaginary_part << "i";
    }

    return out;
}

std::istream& operator>>(std::istream& in, complex& number)
{
    double real = 0.0, imaginary = 0.0;
    char sign = '\0';
    char i_symbol = '\0';

    if (!(in >> real))
    {
        in.setstate(std::ios::failbit);
        return in;
    }


    in >> std::ws >> sign;//узнать чзх
    if (sign != '+' && sign != '-')
    {

        in.putback(sign);
        number._real_part = real;
        number._imaginary_part = 0.0;
        return in;
    }

    if (!(in >> imaginary))
    {
        in.setstate(std::ios::failbit);
        return in;
    }

    in >> std::ws >> i_symbol;
    if (i_symbol != 'i')
    {
        in.setstate(std::ios::failbit);
        return in;
    }

    number._real_part = real;
    number._imaginary_part = (sign == '+') ? imaginary : -imaginary;
    return in;
}
