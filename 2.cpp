#include "2.h"
#include <iostream>

logical_values_array::logical_values_array(unsigned int value)
{
	_value = value;
}

unsigned int logical_values_array::value()const
{
	return _value;
}

logical_values_array logical_values_array::inversion() const
{
	return (~_value);
}

logical_values_array logical_values_array::conjunction(const logical_values_array& other) const
{
	return (_value & other._value);
}

logical_values_array logical_values_array::disjunction(const logical_values_array& other) const
{
	return (_value | other._value);
}

logical_values_array logical_values_array::implication(const logical_values_array& other) const
{
	return(!_value || other._value);
}

logical_values_array logical_values_array::coimplication(const logical_values_array& other) const
{
	return (_value || !other._value);
}

logical_values_array logical_values_array::addition_modulo(const logical_values_array& other) const
{
	return (_value^ other._value);
}

logical_values_array logical_values_array::equivalence(const logical_values_array& other) const
{
	return ((!_value || !other._value) && (_value || other._value));
}

logical_values_array logical_values_array::price_arrow(const logical_values_array& other) const
{
	return(!(_value || other._value));
}

logical_values_array logical_values_array::schaeffer_stroke(const logical_values_array& other) const
{
	return(!(_value && other._value));
}

bool logical_values_array::get_bit(size_t index) const
{
	return ((_value >> index) & 1) != 0U;
}

bool logical_values_array::operator[](size_t index) const
{
	if (index >= sizeof(unsigned int) * 8)
	{
		throw std::out_of_range("Index out of range");
	}
	return get_bit(index);
}

void logical_values_array::to_binary_string(char* buffer) const
{
	unsigned int mask = 1 << (sizeof(_value) * 8 - 1);
	for (int i = 0; i < sizeof(_value) * 8; ++i)
	{
		*buffer++ = ((_value & mask) != 0U) ? '1' : '0';
		mask >>= 1;
	}
	*buffer = '\0';
}