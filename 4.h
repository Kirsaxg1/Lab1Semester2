#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class matrix {

public:

	matrix(size_t i, size_t j);
	matrix(const matrix& other) = default;
	matrix& operator = (const matrix& other) = default;
	~matrix() = default;

	matrix operator+(const matrix& other) const;
	matrix& operator+=(const matrix& other);

	matrix operator*(const matrix& other) const;
	matrix& operator*=(const matrix& other);

	matrix operator-(const matrix& other) const;
	matrix& operator-=(const matrix& other);

	matrix operator*(double other) const;
	matrix& operator*=(double other);


	[[nodiscard]] matrix transposed_matrix()const;
	[[nodiscard]] double determinant() const;
	[[nodiscard]] matrix inverse() const;

	int operator[](size_t index_i, size_t index_j) const;

private:
	double** _data;
	size_t _i;
	size_t _j;

	void allocate();
	void delall();
	
};
#endif // !MATRIX_H
