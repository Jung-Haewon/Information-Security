#include <iostream>
using namespace std;

string railFenceCipher(string plainText, int railNumber);

int main(void)
{
	string plainText, cipherText;
	int railNumber;

	cout << "Input Plain Text : ";
	cin >> plainText;
	cout << "Input rail Number : ";
	cin >> railNumber;
	cipherText = railFenceCipher(plainText, railNumber);
	cout << "Cipher Text : " << cipherText;

	return 0;
}

string railFenceCipher(string plainText, int railNumber)
{
	string* rails = new string[railNumber];
	string cipherText = "";

	int cnt = 0;
	int direction = 1;

	for (char p : plainText)
	{
		rails[cnt] += p;
		cnt += direction;

		if (cnt == railNumber)
		{
			cnt -= 2;
			direction = -1;
		}
		else if (cnt == -1)
		{
			cnt += 2;
			direction = 1;
		}
	}

	for (int i = 0; i < railNumber; i++)
		cipherText += rails[i];

	delete[] rails;

	return cipherText;
}