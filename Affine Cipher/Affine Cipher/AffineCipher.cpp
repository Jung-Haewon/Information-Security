#include <iostream>
#include <string>
using namespace std;

string affineCipherEncryption(string plainText, int k1, int k2);
string affineCipherDecryption(string cipherText, int k1, int k2);
int inversion(int n, int m);
int modular(int n, int m);

int main(void)
{
	string plainText, cipherText;
	int k1, k2, mode;

	cout << "Select Encryption(0), Decryption(1): ";
	cin >> mode;

	switch (mode)
	{
	case 0:
		cout << "Insert Plain Text : ";
		cin.ignore();
		getline(cin, plainText);
		cout << "Insert Key1, Key2 : ";
		cin >> k1 >> k2;
		cipherText = affineCipherEncryption(plainText, k1, k2);
		cout << "Cipher Text : " << cipherText << endl;
		break;
	case 1:
		cout << "Insert Cipher Text : ";
		cin.ignore();
		getline(cin, cipherText);
		cout << "Insert Key1, Key2 : ";
		cin >> k1 >> k2;
		plainText = affineCipherDecryption(cipherText, k1, k2);
		cout << "Plain Text : " << plainText << endl;
		break;
	default:
		cout << "Input Error. You must input 0 or 1" << endl;
		break;
	}

	return 0;
}


int inversion(int n, int m)
{
	for (int i = 0; i < 26; i++)
		if ((n * i) % m == 1)
			return i;
}

int modular(int n, int m)
{
	if (n < 0)
		while (n < 0)
			n += m;
	return n % m;
}

string affineCipherEncryption(string plainText, int k1, int k2)
{
	string cipherText = "";

	for (char p : plainText)
	{
		char c;

		if (p >= 'A' && p <= 'Z')
			c = (((p - 'A') * k1) + k2) % 26 + 'A';
		else if (p >= 'a' && p <= 'z')
			c = (((p - 'a') * k1) + k2) % 26 + 'a';
		else
			c = p;

		cipherText += c;
	}

	return cipherText;
}

string affineCipherDecryption(string cipherText, int k1, int k2)
{
	string plainText = "";
	int inverse = inversion(k1, 26);

	for (char c : cipherText)
	{
		char p;

		if (c >= 'A' && c <= 'Z')
			p = modular(((c - 'A' - k2) * inverse), 26) + 'A';
		else if (c >= 'a' && c <= 'z')
			p = modular(((c - 'a' - k2) * inverse), 26) + 'a';
		else
			p = c;

		plainText += p;
	}

	return plainText;
}