#include "2.h"
#include <iostream>

logic_values_array::logic_values_array(unsigned int value)
{
	_value = value;
}

unsigned int logic_values_array::value()const
{
	return _value;
}

logic_values_array logic_values_array::inversion()const
{
	return ~_value;
}

logic_values_array logic_values_array::congunction(const logic_values_array& other)const
{
	return (_value & other._value);
}

logic_values_array logic_values_array::disjunction(const logic_values_array& other)const
{
	return (_value | other._value);
}

logic_values_array logic_values_array::implication(const logic_values_array& other)const
{
	return (!_value || other._value);
}

logic_values_array logic_values_array::equipment(const logic_values_array& other)const
{
	return(!_value && other._value);
}

logic_values_array logic_values_array::addition_modulo(const logic_values_array& other)const
{
	return (_value ^ other._value);
}

logic_values_array logic_values_array::equivalence(const logic_values_array& other)const
{
	return (!(_value ^ other._value));
}

logic_values_array logic_values_array::arrow_of_the_Pier(const logic_values_array& other)const
{
	return (!(_value || other._value));
}

logic_values_array logic_values_array::Schaeffers_stroke(const logic_values_array& other)const
{
	return (!(_value && other._value));
}

bool logic_values_array::equals(const logic_values_array& first, const logic_values_array& second)
{
	return (first._value == second._value);
}

bool logic_values_array::get_bit(size_t position)const
{
	return ((_value >> position) & 1) != 0U;
}

bool logic_values_array::operator[](size_t index)const
{
	if (index >= sizeof(unsigned int) * 8)
	{
		throw std::out_of_range("Error index range");
	}

	return get_bit(index);
}

void logic_values_array::to_binary_string(char* buffer)const
{
	unsigned int mask = 1 << (sizeof(_value) * 8 - 1);
	for (int i = 0; i < sizeof(_value) * 8; ++i)
		{
		*buffer++=((_value&mask)!= 0U)?'1':'0';
		mask >>= 1;
		}
	*buffer = '\0';
}