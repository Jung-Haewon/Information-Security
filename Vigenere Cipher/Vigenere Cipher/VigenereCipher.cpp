#include <iostream>
#include <string>
using namespace std;

string vigenereCipherEncryption(string plainText, string key);
string vigenereCipherDecryption(string cipherText, string key);
int modular(int n, int m);

int main(void)
{
	string plainText, cipherText, key;
	
	cout << "Input Plain Text : ";
	getline(cin, plainText);
	cout << "Input Key(String) : ";
	getline(cin, key);
	cipherText = vigenereCipherEncryption(plainText, key);
	cout << "Cipher Text : " << cipherText << endl;
	plainText = vigenereCipherDecryption(cipherText, key);
	cout << "Plain Text : " << plainText << endl;

	return 0;
}

string vigenereCipherEncryption(string plainText, string key)
{
	string cipherText = "";
	int keyLen = key.length();
	int* keyStream = new int[keyLen];

	for (int i = 0; i < keyLen; i++)
	{
		if (key[i] >= 'A' && key[i] <= 'Z')
			keyStream[i] = key[i] - 'A';
		else if (key[i] >= 'a' && key[i] <= 'z')
			keyStream[i] = key[i] - 'a';
		else
			keyStream[i] = 0;
	}

	for (int i = 0; i < plainText.length(); i++)
	{
		char c;

		if (plainText[i] >= 'A' && plainText[i] <= 'Z')
			c = (plainText[i] - 'A' + keyStream[i % keyLen]) % 26 + 'A';
		else if (plainText[i] >= 'a' && plainText[i] <= 'z')
			c = (plainText[i] - 'a' + keyStream[i % keyLen]) % 26 + 'a';
		else
			c = plainText[i];

		cipherText += c;
	}

	delete[] keyStream;

	return cipherText;
}

string vigenereCipherDecryption(string cipherText, string key)
{
	string plainText = "";
	int keyLen = key.length();
	int* keyStream = new int[keyLen];

	for (int i = 0; i < keyLen; i++)
	{
		if (key[i] >= 'A' && key[i] <= 'Z')
			keyStream[i] = key[i] - 'A';
		else if (key[i] >= 'a' && key[i] <= 'z')
			keyStream[i] = key[i] - 'a';
		else
			keyStream[i] = 0;
	}

	for (int i = 0; i < cipherText.length(); i++)
	{
		char c;

		if (cipherText[i] >= 'A' && cipherText[i] <= 'Z')
			c = modular(cipherText[i] - 'A' - keyStream[i % keyLen], 26) + 'A';
		else if (cipherText[i] >= 'a' && cipherText[i] <= 'z')
			c = modular(cipherText[i] - 'a' - keyStream[i % keyLen], 26) + 'a';
		else
			c = cipherText[i];

		plainText += c;
	}

	delete[] keyStream;

	return plainText;
}

int modular(int n, int m)
{
	if (n < 0)
		while (n < 0)
			n += m;
	return n % m;
}
