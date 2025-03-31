#ifndef ENCODER_H
#define ENCODER_H

#include <iostream>
#include <fstream>

class encoder {
public:
	encoder(unsigned char*key, size_t size_key);
	~encoder() = default;
	encoder(const encoder& other) = default;
	encoder& operator = (const encoder& other) = default;

	void mutator(unsigned char* key, size_t size_key);
	void encode(const char* Fin, const char* Fout, bool def = true);

private:

	size_t i = 0, j = 0;
	unsigned char S[256];

	void KSA(unsigned char const* key, size_t size_key);
	unsigned char PRGA();
	void swap(unsigned char& a, unsigned char& b);

};

#endif // !ENCODER_H
