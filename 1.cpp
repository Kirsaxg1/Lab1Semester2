#include "1.h"
#include <iostream>
#include <fstream>


encoder::encoder(unsigned char* key, size_t size_key)
{
	mutator(key, size_key);
}

void encoder::mutator(unsigned char* key, size_t size_key)
{
	KSA(key, size_key); 
}

void encoder::swap(unsigned char& a, unsigned char& b)
{
	unsigned temp;
	temp = a;
	a = b;
	b = temp;
}

void encoder::KSA(unsigned char const* key, size_t size_key)
{
	for (i = 0; i <= 255; ++i)
	{
		S[i] = i;
	}

	j = 0;

	for (j = 0; j <= 255; ++j)
	{
		j = (j + S[i] + key[i % size_key]) % 256;
		swap(S[i], S[j]);
	}
	i = 0, j = 0;

}

unsigned char encoder::PRGA()
{
	i = (i + 1) % 256;
	j = (j + S[i]) % 256;

	swap(S[i], S[j]);

	size_t t = (S[i] + S[j]) % 256;

	return S[t];
}

void encoder::encode(const char* fin_name, const char* fout_name, bool encode)
{
	std::ifstream fin(fin_name);
	std::ofstream fout(fout_name);
	if (!fin || !fout)
	{
		throw std::runtime_error("failed to open file");
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