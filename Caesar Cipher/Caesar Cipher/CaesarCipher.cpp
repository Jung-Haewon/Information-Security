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

	cout << "��(��ȣ��)�� �Է��Ͻÿ� : ";
	//cin.ignore();
	getline(cin, plainText);
	cout << "Ű ���� �Է��Ͻÿ� : ";
	cin >> key;

	cipherText = caesarCipher(plainText, key);

	cout << "��ȣȭ(��ȣȭ)�� ��� : " << cipherText << endl;

	return 0;
}