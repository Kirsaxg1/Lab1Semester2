#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include <cstddef>

class logical_values_array {

public:

	~logical_values_array() = default;
	logical_values_array(const logical_values_array& other) = default;
	logical_values_array& operator= (const logical_values_array& other) = default;
	logical_values_array(unsigned int value = 0);

	[[nodiscard]] unsigned int value()const;

	[[nodiscard]] logical_values_array inversion() const;
	[[nodiscard]] logical_values_array conjunction(const logical_values_array& other) const;
	[[nodiscard]] logical_values_array disjunction(const logical_values_array& other) const;
	[[nodiscard]] logical_values_array implication(const logical_values_array& other) const;
	[[nodiscard]] logical_values_array coimplication(const logical_values_array& other) const;
	[[nodiscard]] logical_values_array addition_modulo(const logical_values_array& other) const;
	[[nodiscard]] logical_values_array equivalence(const logical_values_array& other) const;
	[[nodiscard]] logical_values_array price_arrow(const logical_values_array& other) const;
	[[nodiscard]] logical_values_array schaeffer_stroke(const logical_values_array& other) const;

	[[nodiscard]] static bool equals(const logical_values_array& first, const logical_values_array& second)
	{
		return (first._value == second._value);
	}

	[[nodiscard]] bool get_bit(size_t index)const;

	bool operator[](size_t index) const;

	void to_binary_string(char* buffer) const;

private:

	unsigned int _value;
};

#endif // !LOGIC_H
