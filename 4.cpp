#include "4.h"
#include <iostream>

void matrix::allocate()
{
	_data = new double* [_i];
	try
	{
		for (size_t k = 0; k < _i; ++k)
		{
			_data[k] = new double[_j];
		}
	}
	catch (std::bad_alloc& e)
	{
		for (size_t l = 0; l < _i; ++l)
		{
			delete[] _data[l];
		}
		delete[]_data;
		throw;
	}
}

void matrix::delall()
{
	for (int k = 0; k < _i; ++k)
	{
		delete[] _data[_i];
	}
	delete[]_data;
}

matrix::matrix(size_t i, size_t j)
{
	_j = j;
	_i = i;

	allocate();

	for (int k = 0; k < _i; ++k)
	{
		std::memset(_data, 0, sizeof(double)* _j);
	}
}

matrix::~matrix()
{
	delall();
}

matrix& matrix::operator=(const matrix& other)
{
	if (&other == this)
	{
		return *this;
	}

	if (_j != other._j || _i != other._i)
	{
		_j = other._j;
		_i = other._i;
		allocate();
	}
	for (int k = 0; k < _i; ++k)
	{
		std::memcpy(_data[k], other._data[k], sizeof(double) * _j);
	}
	return *this;
}

matrix matrix::operator+(const matrix& other)const
{
	if (_j != other._j || _i != other._i)
	{
		throw std::invalid_argument("Error size matrix");
	}

	matrix ptr(_i, _j);

	for (int k = 0; k < _i; ++k)
	{
		for (int l = 0; l < _j; ++l)
		{
			ptr._data[_i][_j] = _data[_i][_j] + other._data[_i][_j];
		}
	}

	return ptr;

}

matrix& matrix::operator+=(const matrix& other)
{
	*this = *this + other;
	return *this;
}

matrix matrix::operator*(const matrix& other) const
{
	if (_j != other._i)
	{
		throw std::invalid_argument("Error size matrix");
	}

	matrix ptr(_i, _j);

	for (int k = 0; k < _i; ++k)
	{
		for (int l = 0; l < _j; ++l)
		{
			for (int h = 0; h < _j; ++h)
			{
				ptr._data[_i][_j] += _data[_i][_j] * other._data[_i][_j];
			}
		}
	}

	return ptr;
}

matrix& matrix::operator*=(const matrix& other)
{
	*this = *this * other;
	return *this;
}

matrix matrix::operator-(const matrix& other)const
{
	if (_j != other._j || _i != other._i)
	{
		throw std::invalid_argument("Error size matrix");
	}

	matrix ptr(_i, _j);

	for (int k = 0; k < _i; ++k)
	{
		for (int l = 0; l < _j; ++l)
		{
			ptr._data[_i][_j] = _data[_i][_j] - other._data[_i][_j];
		}
	}

	return ptr;

}

matrix& matrix::operator-=(const matrix& other)
{
	*this = *this - other;
	return *this;
}

matrix matrix::operator*(double other) const
{
	matrix ptr(*this);

	for (int k = 0; k < _i; k++)
	{
		for (int h = 0; h < _j; ++h)
		{
			ptr._data[_i][_j] = _data[_i][_j] * other;
		}
	}

	return ptr;
}

matrix& matrix::operator*=(double other)
{
	*this = *this * other;
	return *this;
}