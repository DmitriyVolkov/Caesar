#include "string.h"
#include "iostream"
#include "stdio.h"
#include <fstream>

using namespace std;
void Cezar(char string [500]) //Caesar
{
	char key;
	int shift;
	cout << "Enter the shift: ";
	cin >> shift;
	for (int i = 0; i < strlen(string); i++) //ENCODING
	{
		if (string[i] != 32)
		{

			string[i] += (shift % 26); 
			if (string[i] > 122) 
			{
				string[i] = (string[i] % 122) + 96;
			}
			if (string[i] < 97)
			{
				string[i] += 230;
			}
		}

	}
	cout << "Encoded string: " << string << endl;
	
	for (int i = 0; i < strlen(string); i++) //DECODING
	{
		if (string[i] != 32)
		{
			string[i] -= shift % 26; 
			while (string[i] < 97)
			{
				string[i] += 26;
			}
		}
	}
	cout << "Decoded string: " << string << endl;
	
}
void Vigenere(char string[500]) //Vigener
{
	int a;
	cout.flush();
	int j;
	cout << "Enter the secret word: ";
	cin >> a;
	char shift[100];
	gets(shift);
	for (int i = 0; i < strlen(string); i++) //ENCODING
	{
		if (string[i] != 32)
		{
			j = i % strlen(shift);
			shift[j] = shift[j] % 96;
			string[i] += shift[j]; 
			if (string[i] > 122)  
			{
				string[i] = (string[i] % 122) + 96;
			}
			if (string[i] < 97)
			{
				string[i] += 230;
			}
		}

	}
	cout << "Encoded string: " << string << endl;

	for (int i = 0; i < strlen(string); i++) //DECODING
	{
		if (string[i] != 32)
		{
			j = i % strlen(shift);
			shift[j] = shift[j] % 96;
			string[i] -= shift[j]; 
			while (string[i] < 96)
			{
				string[i] = string[i] + 26;
			}
		}
	}
	cout << "Decoded string: " << string << endl;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	char string[500];
	cout << "Enter text: "; 
	gets(string); 
	int key;
	cout << "1 - Caesar" << endl << "2 - Vigener" << endl; 
	cout << "Enter the encryption method: ";
	cin >> key;
	switch (key)
	{
		case 1:
			Cezar(string);
			break;
		case 2:
			Vigenere(string);
			break;
	}
	system("pause");
	return 0;
}

