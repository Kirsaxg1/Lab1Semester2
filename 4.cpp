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

matrix matrix::transposed_matrix() const
{
	matrix result(_j, _i);
	for (size_t row = 0; row < _i; ++row)
	{
		for (size_t col = 0; col < _j; ++col)
		{
			result._data[col][row] = _data[row][col];
		}
	}
	return result;
}

double matrix::determinant() const
{
//TODO
}

matrix matrix::transposed_matrix() const
{
	matrix result(_j, _i);
	for (size_t row = 0; row < _i; ++row)
	{
		for (size_t col = 0; col < _j; ++col)
		{
			result._data[col][row] = _data[row][col];
		}
	}
	return result;
}

matrix matrix::inverse() const
{
	if (_i != _j)
	{
		throw std::invalid_argument("Error arg");
	}

	double det = determinant();
	if (std::abs(det) < 1e-9)
	{ 
		throw std::runtime_error("Error:)");
	}

	if (_i == 1)
	{
		matrix result(1, 1);
		result._data[0][0] = 1.0 / _data[0][0];
		return result;
	}

	if (_i == 2)
	{
		matrix result(2, 2);
		result._data[0][0] = _data[1][1] / det;
		result._data[0][1] = -_data[0][1] / det;
		result._data[1][0] = -_data[1][0] / det;
		result._data[1][1] = _data[0][0] / det;
		return result;
	}

	matrix result(_i, _j);

	for (size_t row = 0; row < _i; ++row)
	{
		for (size_t col = 0; col < _j; ++col)
		{
			// Create submatrix
			matrix submatrix(_i - 1, _j - 1);
			size_t sub_row = 0;
			for (size_t i = 0; i < _i; ++i)
			{
				if (i == row) continue;
				size_t sub_col = 0;
				for (size_t j = 0; j < _j; ++j)
				{
					if (j == col) continue;
					submatrix._data[sub_row][sub_col] = _data[i][j];
					sub_col++;
				}
				sub_row++;
			}

			result._data[col][row] = std::pow(-1, row + col) * submatrix.determinant() / det;
		}
	}

	return result;
}

