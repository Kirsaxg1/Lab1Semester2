#ifndef  LOGIC_H
#define LOGIC_H

class logic_values_array {

	unsigned int _value;

public:

	logic_values_array(unsigned int value = 0);
	~logic_values_array() = default;
	logic_values_array(const logic_values_array& other) = default;
	logic_values_array& operator =(const logic_values_array& other) = default;

	unsigned int value()const;

	logic_values_array inversion()const;
	logic_values_array congunction(const logic_values_array& other)const;//объект который лежит под this ( вызывающий ) неизменяемый, если & то объект невремнный
	logic_values_array disjunction(const logic_values_array& other)const;
	logic_values_array implication(const logic_values_array& other)const;
	logic_values_array equipment(const logic_values_array& other)const;
	logic_values_array addition_modulo(const logic_values_array& other)const;
	logic_values_array equivalence(const logic_values_array& other)const;
	logic_values_array arrow_of_the_Pier(const logic_values_array& other)const;
	logic_values_array Schaeffers_stroke(const logic_values_array& other)const;

	static bool equals(const logic_values_array& first, const logic_values_array& second);

	bool get_bit(size_t position)const;
	bool operator[](size_t index) const;

	void to_binary_string(char* buffer)const;

};

#endif // ! LOGIC_H
