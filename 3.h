#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class complex {

	double _actual_part;
	double _imaginary_part;

public:

	complex(const complex& other) = default;
	~complex() = default;
	complex(double actual_part = 0,double imaginary_part = 0);
	complex& operator = (const complex& other) = default;

	complex operator + (const complex& other) const;
	complex& operator +=(const complex& other);

	complex operator - (const complex& other) const;
	complex& operator -= (const complex& other);

	complex operator * (const complex& other) const;
	complex& operator *= (const complex& other);

	complex operator / (const complex& other) const;
	complex& operator /= (const complex& other);

	[[nodiscard]] double abs()const;
	[[nodescard]] double arg()const;


	friend std::ostream& operator<<(std::ostream& out, const complex& number);
	friend std::istream& operator>>(std::istream& in, complex& number);

};


#endif // !COMPLEX_H
