#include "3.h"
#include <iostream>

complex::complex(double actual_part , double imaginary_part )
{
	_actual_part = actual_part;
	_imaginary_part = imaginary_part;
}

complex complex::operator+(const complex& other)const
{
	return { _actual_part + other._actual_part, _imaginary_part + other._imaginary_part };
}

complex &complex::operator+=(const complex& other)
{
	*this = *this + other;
	return *this;
}

complex complex::operator*(const complex& other)const
{
	complex data;
	data._actual_part = (_actual_part * other._actual_part) - (_imaginary_part * other._imaginary_part);
	data._imaginary_part = (_actual_part * other._imaginary_part) + (_imaginary_part * other._actual_part);
	return data;
}

complex& complex::operator*=(const complex& other)
{
	*this = *this * other;
	return *this;

}

complex complex::operator-(const complex& other)const
{
	return { _actual_part - other._actual_part, _imaginary_part - other._imaginary_part };
}

complex &complex::operator-=(const complex& other)
{
	*this = *this - other;
	return *this;
}

complex complex::operator/(const complex& other) const
{
	double denominator = other._actual_part * other._actual_part + other._imaginary_part * other._imaginary_part;
	if (denominator == 0.0)
	{
		throw std::runtime_error("division zero complex number");
	}
	double real = (_actual_part * other._actual_part + _imaginary_part * other._imaginary_part) / denominator;
	double imag = (_imaginary_part * other._actual_part - _actual_part * other._imaginary_part) / denominator;
	return complex(real, imag);
}

complex &complex::operator/=(const complex& other)
{
	*this = *this / other;
	return *this;
}

double complex::abs()const
{
	return std::sqrt((_actual_part * _actual_part) + (_imaginary_part * _imaginary_part));
}

double complex::arg()const
{
	return std::atan(_actual_part / _imaginary_part);
}

std::ostream& operator<<(std::ostream& out, const complex& number)
{
	out << number._actual_part;
	if (number._imaginary_part >= 0)
	{
		out << "+";
	}
	out << number._imaginary_part << "i";
	return out;
}

std::istream& operator>>(std::istream& in, complex& number)
{
	in >> number._actual_part >> number._imaginary_part;
	return in;
}