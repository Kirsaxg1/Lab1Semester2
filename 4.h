#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <iostream>
#include <stdexcept>

class matrix final {
    class matrix_row {
    private:
        double* _row_data;
        size_t _cols;
    public:
        matrix_row(double* row_data, size_t cols)
            : _row_data(row_data), _cols(cols)
        {
        }

        double& operator[](size_t col)
        {
            if (col >= _cols) throw std::out_of_range("Column index out of range");
            return _row_data[col];
        }

        const double& operator[](size_t col) const
        {
            if (col >= _cols) throw std::out_of_range("Column index out of range");
            return _row_data[col];
        }
    };

private:
    double** _elements;
    size_t _rows;
    size_t _cols;

    void allocate();
    void free();
    void copy_data(const matrix& source);
    void move_data(matrix&& source) noexcept;

    //[[nodiscard]] matrix augment_with_identity() const;
    //void apply_gaussian(matrix& extended) const;
    //[[nodiscard]] matrix extract_inverse_part(const matrix& extended) const;

public:
    matrix(size_t rows, size_t cols);
    matrix(const matrix& other);
    matrix(matrix&& other) noexcept;
    ~matrix();

    matrix& operator=(const matrix& other);
    matrix& operator=(matrix&& other) noexcept;

    matrix operator+(const matrix& rhs) const;
    matrix& operator+=(const matrix& rhs)&;

    matrix operator-(const matrix& rhs) const;
    matrix& operator-=(const matrix& rhs)&;

    matrix operator*(const matrix& rhs) const;
    matrix& operator*=(const matrix& rhs)&;

    matrix operator*(double scalar) const;
    matrix& operator*=(double scalar)&;

    friend matrix operator*(double scalar, const matrix& mat);

    matrix_row operator[](size_t row)
    {
        if (row >= _rows) throw std::out_of_range("Row index out of range");
        return matrix_row(_elements[row], _cols);
    }

    const matrix_row operator[](size_t row) const
    {
        if (row >= _rows) throw std::out_of_range("Row index out of range");
        return matrix_row(_elements[row], _cols);
    }

    double& at(size_t row, size_t col)
    {
        if (row >= _rows || col >= _cols)
            throw std::out_of_range("Matrix index out of bounds");
        return _elements[row][col];
    }

    const double& at(size_t row, size_t col) const
    {
        if (row >= _rows || col >= _cols)
            throw std::out_of_range("Matrix index out of bounds");
        return _elements[row][col];
    }

    matrix transposed() const;
    double determinant() const;
    matrix inverse() const;

    friend std::ostream& operator<<(std::ostream& os, const matrix& mat);
    friend std::istream& operator>>(std::istream& is, matrix& mat);

    size_t row_count() const { return _rows; }
    size_t col_count() const { return _cols; }

    static double abs(double x)
    {
        return x < 0 ? -x : x;
    }

    template<typename T>
    static void swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    class inverse_error : public std::logic_error {
    public:
        explicit inverse_error(const std::string& msg)
            : std::logic_error(msg) {}
    };
};

#endif // MATRIX_H