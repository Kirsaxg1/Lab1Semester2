#include "3.h"
#include <iostream>

complex::complex(double actual_part = 0, double imaginary_part = 0)
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

complex complex::operator/(const complex& other)const
{
	//todo
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

