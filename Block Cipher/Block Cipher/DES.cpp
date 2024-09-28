#include <iostream>
using namespace std;

int IPTable[64] = {
	58, 50, 42, 34, 26, 18, 10,  2,
	60, 52, 44, 36, 28, 20, 12,  4,
	62, 54, 46, 38, 30, 22, 14, 16,
	64, 56, 48, 40, 32, 24, 16,  8,
	57, 49, 41, 33, 25, 17,  9,  1,
	59, 51, 43, 35, 27, 19, 11,  3,
	61, 53, 45, 37, 29, 21, 13,  5,
	63, 55, 47, 39, 31, 23, 15,  7
};

int IIPTable[64] = {
	40, 8, 48, 16, 56, 24, 64, 32,
	39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30,
	37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28,
	35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26,
	33, 1, 41,  9, 49, 17, 57, 25
};

int EPTable[48] = {
	32,  1,  2,  3,  4,  5,  4,  5,
	 6,  7,  8,  9,  8,  9, 10, 11,
	12, 13, 12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21, 20, 21,
	22, 23, 24, 25, 24, 25, 26, 27,
	28, 29, 28, 29, 30, 31, 32, 31
};

void ip(unsigned char* in, unsigned char* out);
void iip(unsigned char* in, unsigned char* out);
void ep(unsigned int Right32, unsigned char* out);

int main(void)
{

}

void ip(unsigned char* in, unsigned char* out)
{
	unsigned char index, bit, mask = 0x80;

	for (int i = 0; i < 64; i++)
	{
		index = (IPTable[i] - 1) / 8;
		bit = (IPTable[i] - 1) % 8;

		if (in[index] & (mask >> bit))
			out[i / 8] |= mask >> (i % 8);
	}
}

void iip(unsigned char* in, unsigned char* out)
{
	unsigned char index, bit, mask = 0x80;
	
	for (int i = 0; i < 64; i++)
	{
		index = (IIPTable[i] - 1) / 8;
		bit = (IIPTable[i] - 1) % 8;

		if (in[index] & (mask >> bit))
			out[i / 8] |= mask >> (i % 8);
	}
}

void ep(unsigned int Right32, unsigned char* out)
{
	unsigned int bit8_Mask = 0x80;
	unsigned int bit32_Mask = 0x80000000;

	for (int i = 0; i < 38; i++)
		if (Right32 & (bit32_Mask >> EPTable[i] - 1))
			out[i/8] |= (unsigned char)(bit8_Mask >> (i % 8));
}