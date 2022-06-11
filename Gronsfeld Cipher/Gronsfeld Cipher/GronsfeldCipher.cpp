#include <iostream>
#include <string>
using namespace std;

string gronsfeldCipherEncryption(string plainText, string key);
string gronsfeldCipherDecryption(string cipherText, string key);
int modular(int n, int m);

int main(void)
{
	string plainText, cipherText, key;

	cout << "Input Plain Text : ";
	getline(cin, plainText);
	cout << "Input Key(String) : ";
	//cin.ignore();
	getline(cin, key);
	cipherText = gronsfeldCipherEncryption(plainText, key);
	cout << "Cipher Text : " << cipherText << endl;
	plainText = gronsfeldCipherDecryption(cipherText, key);
	cout << "Plain Text : " << plainText << endl;

	return 0;
}

string gronsfeldCipherEncryption(string plainText, string key) {
	string cipherText = "";
	int keyLen = key.length();

	for (int i = 0; i < plainText.length(); i++) {
		char c;

		if (plainText[i] >= 'A' && plainText[i] <= 'Z')
			c = (plainText[i] - 'A' + (key[i % keyLen] - '0')) % 26 + 'A';
		else if (plainText[i] >= 'a' && plainText[i] <= 'z')
			c = (plainText[i] - 'a' + (key[i % keyLen] - '0')) % 26 + 'a';
		else
			c = plainText[i];
		cipherText += c;
	}
	return cipherText;
}

string gronsfeldCipherDecryption(string cipherText, string key) {
	string plainText = "";
	int keyLen = key.length();

	for (int i = 0; i < cipherText.length(); i++) {
		char c;

		if (cipherText[i] >= 'A' && cipherText[i] <= 'Z')
			c = modular(cipherText[i] - 'A' - (key[i % keyLen] - '0'), 26) + 'A';
		else if (cipherText[i] >= 'a' && cipherText[i] <= 'z')
			c = modular(cipherText[i] - 'a' - (key[i % keyLen] - '0'), 26) + 'a';
		else
			c = cipherText[i];
		plainText += c;
	}
	return plainText;
}

int modular(int n, int m) {
	if (n < 0)
		while (n < 0)
			n += m;
	return n % m;
}
