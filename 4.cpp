#include "4.h"
#include <cmath>



void matrix::allocate()
{
    _elements = new double* [_rows];
    
    try
    {
        for (size_t i = 0; i < _rows; ++i)
        {
            _elements[i] = new double[_cols] {};
        }
    }
    catch (...)
    {
        free();
        throw;
    }


}

void matrix::free()
{
    if (_elements)
    {
        for (size_t i = 0; i < _rows; ++i)
            delete[] _elements[i];
        delete[] _elements;
        _elements = nullptr;
    }
}

void matrix::copy_data(const matrix& source)
{
    if (this == &source)
    {
        return;
    }

    _rows = source._rows;
    _cols = source._cols;
    allocate();

    for (size_t i = 0; i < _rows; ++i)
        std::memcpy(_elements[i], source._elements[i], _cols*sizeof(double));
}

void matrix::move_data(matrix&& source) noexcept
{
    _rows = source._rows;
    _cols = source._cols;
    _elements = source._elements;
    source._elements = nullptr;
    source._rows = 0;
    source._cols = 0;
}

matrix::matrix(size_t rows, size_t cols) : _rows(rows), _cols(cols)
{
    if (rows == 0 || cols == 0)
    {
        _rows = 0;
        _cols = 0;
        return;
    }

    try
    {
        allocate();

        for (size_t i = 0; i < _rows; ++i)
        {
            for (size_t j = 0; j < _cols; ++j)
            {
                _elements[i][j] = 0.0;
            }
        }
    }
    catch (...)
    {
        free();
        throw;
    }
}

matrix::~matrix()
{
    free();
}

matrix::matrix(const matrix& other)
{
    copy_data(other);
}

matrix& matrix::operator=(const matrix& other)
{
    if (this != &other)
    {
        free();
        copy_data(other);
    }
    return *this;
}

matrix& matrix::operator=(matrix&& other) noexcept
{
    if (this != &other)
    {
        free();
        move_data(std::move(other));
    }
    return *this;
}

matrix matrix::operator+(const matrix& other) const
{
    if (_rows != other._rows || _cols != other._cols)
        throw std::invalid_argument("Matrix size must match for addition.");
    matrix res(_rows, _cols);
    for (size_t i = 0; i < _rows; ++i)
        for (size_t j = 0; j < _cols; ++j)
            res._elements[i][j] = _elements[i][j] + other._elements[i][j];
    return res;
}
// ЧЕРЕЗ += реализовать +
matrix& matrix::operator+=(const matrix& other)&
{
    *this = *this + other;
    return *this;
}

matrix matrix::operator-(const matrix& other) const
{
    if (_rows != other._rows || _cols != other._cols)
        throw std::invalid_argument("Matrix sizes must match for subtraction.");
    matrix res(_rows, _cols);
    for (size_t i = 0; i < _rows; ++i)
        for (size_t j = 0; j < _cols; ++j)
            res._elements[i][j] = _elements[i][j] - other._elements[i][j];
    return res;
}

matrix& matrix::operator-=(const matrix& other)&
{
    *this = *this - other;
    return *this;
}

matrix matrix::operator*(const matrix& other) const
{
    if (_cols != other._rows)
        throw std::invalid_argument("Inner matrix dimensions must agree.");
    matrix res(_rows, other._cols);
    for (size_t i = 0; i < _rows; ++i)
        for (size_t j = 0; j < other._cols; ++j)
            for (size_t k = 0; k < _cols; ++k)
                res._elements[i][j] += _elements[i][k] * other._elements[k][j];
    return res;
}

matrix& matrix::operator*=(const matrix& other)&
{
    *this = *this * other;
    return *this;
}

matrix matrix::operator*(double val) const
{
    matrix copy_obj = (*this);
    return copy_obj *= val;
}

matrix& matrix::operator*=(double val)&
{
    for (size_t i = 0; i < _rows; ++i)
        for (size_t j = 0; j < _cols; ++j)
            _elements[i][j] *= val;
    return *this;
}

matrix operator*(double val, const matrix& mat)
{
    return mat * val;
}
// ПЕРЕДЕЛАТЬ как отдельный класс 
//double* matrix::operator[](size_t row)
//{
//    if (row >= _rows) throw std::out_of_range("Row index out of range.");
//    return _elements[row];
//}

//const double* matrix::operator[](size_t row) const
//{
//    if (row >= _rows) throw std::out_of_range("Row index out of range.");
//    return _elements[row];
//}

//double& matrix::at(size_t row, size_t col)
//{
//    if (row >= _rows || col >= _cols) throw std::out_of_range("Matrix index out of bounds.");
//    return _elements[row][col];
//}

//const double& matrix::at(size_t row, size_t col) const
//{
//    if (row >= _rows || col >= _cols) throw std::out_of_range("Matrix index out of bounds.");
//    return _elements[row][col];
//}

matrix matrix::transposed() const
{
    matrix res(_cols, _rows);
    for (size_t i = 0; i < _rows; ++i)
        for (size_t j = 0; j < _cols; ++j)
            res._elements[j][i] = _elements[i][j];
    return res;
}

double matrix::determinant() const
{
    if (_rows != _cols)
        throw std::invalid_argument("Determinant only defined for square matrices.");

    matrix temp(*this);
    double det = 1.0;
    const double epsilon = 1e-10;

    for (size_t i = 0; i < _rows; ++i)
    {
        size_t pivot = i;
        for (size_t j = i + 1; j < _rows; ++j)
        {
            if (matrix::abs(temp._elements[j][i]) > matrix::abs(temp._elements[pivot][i]))
            {
                pivot = j;
            }
        }

        if (matrix::abs(temp._elements[pivot][i]) < epsilon)
        {
            return 0.0;
        }

        if (i != pivot)
        {
            matrix::swap(temp._elements[i], temp._elements[pivot]);
            det = -det;
        }

        det *= temp._elements[i][i];

        // исключение гауса
        for (size_t j = i + 1; j < _rows; ++j)
        {
            double factor = temp._elements[j][i] / temp._elements[i][i];
            for (size_t k = i; k < _cols; ++k)
            {
                temp._elements[j][k] -= factor * temp._elements[i][k];
            }
        }
    }
    return det;
}

matrix matrix::inverse() const
{
    if (_rows != _cols)
        throw std::invalid_argument("Inverse only defined for square matrices.");
    if (matrix::abs(this->determinant()) < 1e-9)
        throw inverse_error("Matrix is singular.");

    size_t n = _rows;
    matrix aug(n, n + 2);
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
            aug._elements[i][j] = _elements[i][j];
        aug._elements[i][n + i] = 1;
    }

    for (size_t i = 0; i < n; ++i)
    {
        size_t pivot = i;
        for (size_t j = i + 1; j < n; ++j)
            if (matrix::abs(aug._elements[j][i]) > std::abs(aug._elements[pivot][i]))
                pivot = j;
        if (pivot != i)
            matrix::swap(aug._elements[i], aug._elements[pivot]);

        double div = aug._elements[i][i];
        for (size_t j = 0; j < 2 * n; ++j)
            aug._elements[i][j] /= div;

        for (size_t k = 0; k < n; ++k)
        {
            if (k == i) continue;
            double f = aug._elements[k][i];
            for (size_t j = 0; j < 2 * n; ++j)
                aug._elements[k][j] -= f * aug._elements[i][j];
        }
    }

    matrix inv(n, n);
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            inv._elements[i][j] = aug._elements[i][n + j];
    return inv;
}

std::ostream& operator<<(std::ostream& os, const matrix& mat)
{
    for (size_t i = 0; i < mat._rows; ++i)
    {
        for (size_t j = 0; j < mat._cols; ++j)
        {
            os << mat._elements[i][j] << " ";
        }
        os << '\n';
    }
    return os;
}

std::istream& operator>>(std::istream& is, matrix& mat)
{
    for (size_t i = 0; i < mat._rows; ++i)
    {
        for (size_t j = 0; j < mat._cols; ++j)
        {
            is >> mat._elements[i][j];
        }
    }
    return is;
}