#include <iostream>
#include <string>
using namespace std;

string caesarCipher(string plainText, int key)
{
	string cipherText = "";

	for (char p : plainText)
	{
		char c;

		if (p >= 'A' && p <= 'Z')
			c = ((p - 'A' + key) % 26) + 'A';
		else if (p >= 'a' && p <= 'z')
			c = ((p - 'a' + key) % 26) + 'a';
		else
			c = p;

		cipherText += c;
	}

	return cipherText;
}

int main(void)
{
	string plainText, cipherText;
	int key;

	cout << "평문(암호문)을 입력하시오 : ";
	//cin.ignore();
	getline(cin, plainText);
	cout << "키 값을 입력하시오 : ";
	cin >> key;

	cipherText = caesarCipher(plainText, key);

	cout << "암호화(복호화)된 결과 : " << cipherText << endl;

	return 0;
}