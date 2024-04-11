#include <iostream>
#include <cmath>
#include <string>
//#include <vector>

using namespace std;

void myLocale()
{
	system("chcp 1251");
	system("cls");
}

void myInput(int &a, int &b, string &str)
{
	cout << "Задайте число а: ";
	cin >> a;
	cout << "\nВведите число b: ";
	cin >> b;
	cout << "\nВведите строку для шифровки: ";
	cin >> str;
}

string encrypt(string message, int a, int b)
{
	string alph = "abcdefghijklmnopqrstuvwxyz";
	string encryptMessage = "";

	for (int i = 0; i < message.length(); i++)
	{
		encryptMessage += alph[(((a * (message[i])) + b) % 26)];
	}

	return encryptMessage;
}

string decrypt(string message, int a, int b)
{
	string alph = "abcdefghijklmnopqrstuvwxyz";
	string decryptMessage = "";
	float y2 = 0, y1 = 1, q = 0, r = 1, y = 0, num = 0;
	int n = 26, minusA = 0, i = 0;

	cout << "\n| N | q | r | y | n | a | y2 | y1 |" << endl;

	while (r != 0)
	{
		cout << "| " << (i + 1) << " | " << q << " | " << r << " | " << y << " | " << n << " | " << a << " | " << y2 << " | " << y1 << " |" << endl;
		num = n / a;
		q = floor(num);
		r = n % a;
		y = y2 - q * y1;

		if (r == 0)
		{
			y2 = y1;
			minusA = y2;
			i++;
			cout << "| " << (i + 1) << " | " << q << " | " << r << " | " << y << " | " << n << " | " << a << " | " << y2 << " | " << y1 << " |" << endl;
			break;
		}
		else
		{
			n = a;
			a = r;
			y2 = y1;
			y1 = y;
			i++;
		}
	}

	if (minusA < 0) minusA += 26;

	for (int i = 0; i < message.length(); i++)
	{
		decryptMessage += alph[((((message[i] - 8) - b) * minusA) % 26)]; //Смещение на 8
	}

	return decryptMessage;
}

void myOutput(string str)
{
	cout << "\nЗашифрованная строка: " << str << endl;
}

int main()
{
	int myA, myB;
	string myStr, myEncryptStr, myDecryptStr;

	myLocale();
	myInput(myA, myB, myStr);
	myEncryptStr = encrypt(myStr, myA, myB);
	myOutput(myEncryptStr);
	myDecryptStr = decrypt(myEncryptStr, myA, myB);
	myOutput(myDecryptStr);
	system("pause");

	return 0;
}