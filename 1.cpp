#include "1.h"
#include <iostream>
#include <fstream>

void encoder::swap(unsigned char& a, unsigned char& b)
{
	unsigned temp;
	temp = a;
	a = b;
	b = temp;
}

encoder::encoder(unsigned char* key, size_t key_size)
{
	mutator(key, key_size);
}

void encoder::mutator(unsigned char* key, size_t key_size)
{
	KSA(key, key_size);
}

void encoder::KSA(unsigned char const* key, size_t key_size)
{
	for (i = 0; i < KS; ++i)//256
	{
		S[i] = i;
	}

	j = 0;

	for (i = 0; i < KS; ++i)
	{
		j = (j + S[i] + key[i % key_size]) % KS;
		swap(S[i], S[j]);
	}
	i = 0, j = 0;
}

unsigned char encoder::PRGA()
{

	i = (i + 1) % KS;
	j = (j + S[i]) % KS;
	
	swap(S[i], S[j]);

	size_t t = (S[i] + S[j]) % KS;
	
	return S[t];
}

void encoder::encode(char const* Fin, char const* Fout, bool def)
{
	std::ifstream fin(Fin);
	std::ofstream fout(Fout);

	if (!fin || !fout)
	{
		throw std::runtime_error("Error open file");
	}

	unsigned char buffer[4096];

	while (!fin.eof())
	{
		fin.read(reinterpret_cast<char*>(buffer), sizeof(buffer));
		size_t read_bytes = fin.gcount();
		if (read_bytes > 0)
		{
			for (int k = 0; k < read_bytes; ++k)
			{
				buffer[k] ^= PRGA();
			}
			fout.write(reinterpret_cast<char*>(buffer),
				static_cast<long>(read_bytes));
		}
	}
	fin.close();
	fout.close();
}