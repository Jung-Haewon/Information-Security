#include <iostream>
using namespace std;

string encryption(string plainText, string key);
string decryption(string cipherText, string key);

int main(void)
{
	string plainText, cipherText, key;

	cout << "Input Plain Text : ";
	cin >> plainText;
	cout << "Input Keys : ";
	cin >> key;
	cipherText = encryption(plainText, key);
	cout << "Cipher Text : " << cipherText << endl;
	plainText = decryption(cipherText, key);
	cout << "Plain Text : " << plainText << endl;

	return 0;
}

string encryption(string plainText, string key)
{
	string cipherText = "";
	string block = "";

	for (int i = 0; i < plainText.length(); i++)
	{
		block += plainText[i];
		
		if (block.length() == key.length())
		{
			for (char k : key)
				cipherText += block[k - '0' - 1];

			block = "";
		}
		else if (i == plainText.length() - 1)
			cipherText += block;
	}

	return cipherText;
}

string decryption(string cipherText, string key)
{
	int* inversionKey = new int[key.length()];
	string plainText = "";
	string block = "";

	for (int i = 0; i < key.length(); i++)
		inversionKey[key[i] - '0' - 1] = i;

	for (int i = 0; i < cipherText.length(); i++)
	{
		block += cipherText[i];

		if (block.length() == key.length())
		{
			for (int j = 0; j < key.length(); j++)
				plainText += block[inversionKey[j]];

			block = "";
		}
		else if (i == cipherText.length() - 1)
			plainText += block;
	}
	delete[] inversionKey;
	return plainText;
}