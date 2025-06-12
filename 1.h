#ifndef ENCODER_H
#define ENCODER_H

#include <iostream>
#include <fstream>

class encoder {

	size_t i = 0, j = 0;
	unsigned char S[256];
	unsigned int KS = 256;

	unsigned char PRGA();
	void KSA(unsigned char const* key, size_t key_size);

	void swap(unsigned char& a, unsigned char& b);

public:

	encoder(unsigned char* key, size_t key_size);
	~encoder() = default;
	encoder(const encoder& other) = default;
	encoder& operator=(const encoder& other) = default;

	void encode(char const* Fin, char const* Fout, bool def = true);
	void mutator(unsigned char* key, size_t key_size);

};
#endif // !ENCODER_H
