#include <iostream>
#include <iomanip>
#include "Header1.h"
using namespace std;
//int main()
//{
	/* #1
	char mystr[255];
	cout << "Enter line:" << endl;
	cin.getline(mystr, 255);

	int count_a = 0, count_o = 0;
	CountElements(count_a, count_o, mystr);
	cout << "Count 'a' --> " << count_a << endl;
	cout << "Count 'o' --> " << count_o << endl;
	*/




	/* #2
	char mystr[255];
	cout << "Enter line:" << endl;
	cin.getline(mystr, 255);

	int count_letters = 0, count_digits = 0, count_spaces = 0;
	CountSymbols(65, 90, count_letters, mystr);
	CountSymbols(97, 122, count_letters, mystr);
	CountSymbols(48, 57, count_digits, mystr);
	CountSymbols(32, 32, count_spaces, mystr);
	cout << "Count letters: " << count_letters << endl;
	cout << "Count digits: " << count_digits << endl;
	cout << "Count spaces: " << count_spaces << endl;
	*/




	/* #3
	char mystr[255];
	cout << "Enter line:" << endl;
	cin.getline(mystr, 255);

	_strupr_s(mystr);
	cout << mystr << endl;
	_strlwr_s(mystr);
	cout << mystr << endl;
	*/




	/* #4
	char mystr[255];
	cout << "Enter line:" << endl;
	cin.getline(mystr, 255);

	int lenStr = 0;
	MyStrLen(mystr, lenStr);
	cout << "Str length: " << lenStr << endl;
	*/




	/* #5
	char mystr[255];
	cout << "Enter line:" << endl;
	cin.getline(mystr, 255);

	char* pstr = mystr;
	char symbol;
	cout << "Enter symbol to delete: ";
	cin >> symbol;

	char* newStr = DeleteSymbol(symbol, pstr);
	char myNewStr[255];
	for (int i = 0;; i++)
	{
		if (*(newStr + i) == '\0')
		{
			myNewStr[i] = '\0';
			break;
		}
		myNewStr[i] = *(newStr + i);
	}
	cout << myNewStr << endl;
	*/




	//Rozrobyty prohramu, yaka zchytuye z ekranu ryadok, a potim vydaye statystyku:
	// kil?kist? probil?nykh symvoliv(probiliv), holosnykh, pryholosnykh, znakiv punktuatsiyi.
	// Vvedennya peredbachayet?sya anhlomovnym.
	/*
	char mystr[255];
	cout << "Enter line:" << endl;
	cin.getline(mystr, 255);

	int spaceCount = 0, countHolosnykh = 0, countPryholosnykh = 0, countZnakiv = 0;
	char* pstr = mystr;
	SpaceCount(pstr, spaceCount);
	cout << "Space count: " << spaceCount << endl;
	LettersCount(pstr, countHolosnykh, countPryholosnykh);
	cout << "Count holosnykh: " << countHolosnykh << endl;
	cout << "Count pryholosnykh: " << countPryholosnykh << endl;
	CountZnakiv(pstr, countZnakiv);
	cout << "Count znakiv: " << countZnakiv << endl;
	*/
	//}

void CountZnakiv(char* pstr, int& lcounter)
{
	for (int i = 0;; i++)
	{
		if (*(pstr + i) == '\0') break;
		if ((*(pstr + i) >= (char)44 && *(pstr + i) <= (char)47) || *(pstr + i) == (char)33 || *(pstr + i) == (char)34 || *(pstr + i) == (char)39 || *(pstr + i) == (char)40 || *(pstr + i) == (char)41 || *(pstr + i) == (char)58 || *(pstr + i) == (char)59 || *(pstr + i) == (char)63 || *(pstr + i) == (char)91 || *(pstr + i) == (char)93 || *(pstr + i) == (char)123 || *(pstr + i) == (char)125 || *(pstr + i) == (char)171 || *(pstr + i) == (char)187)
		{
			lcounter++;
		}
	}
}

void LettersCount(char* pstr, int& lhcounter, int& lpcounter)
{
	for (int i = 0;; i++)
	{
		if (*(pstr + i) == '\0') break;
		if (*(pstr + i) >= (char)65 && *(pstr + i) <= (char)90)
		{
			if (*(pstr + i) == (char)65 || *(pstr + i) == (char)69 || *(pstr + i) == (char)73 || *(pstr + i) == (char)79 || *(pstr + i) == (char)85 || *(pstr + i) == (char)89)
			{
				lhcounter++;
				continue;
			}
			lpcounter++;
		}
		if (*(pstr + i) >= (char)97 && *(pstr + i) <= (char)122)
		{
			if (*(pstr + i) == (char)97 || *(pstr + i) == (char)101 || *(pstr + i) == (char)105 || *(pstr + i) == (char)111 || *(pstr + i) == (char)117 || *(pstr + i) == (char)121)
			{
				lhcounter++;
				continue;
			}
			lpcounter++;
		}
	}
}

void SpaceCount(char* pstr, int& lcounter)
{
	for (int i = 0;; i++)
	{
		if (*(pstr + i) == '\0') break;
		if (*(pstr + i) == (char)32) lcounter++;
	}
}

char* DeleteSymbol(char symbol, char* pstr)
{
	char newStr[255];
	int counter = 0;
	for (int i = 0;; i++)
	{
		if (*(pstr + i) == '\0')
		{
			newStr[counter] = '\0';
			break;
		}
		if (*(pstr + i) != symbol)
		{
			newStr[counter] = *(pstr + i);
			counter++;
		}
	}

	return newStr;
}

void MyStrLen(char str[], int& lcounter)
{
	for (int i = 0;; i++)
	{
		if (str[i] == '\0') break;
		lcounter++;
	}
}

void CountSymbols(int symbol1, int symbol2, int& lcounter, char str[])
{
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = symbol1; j <= symbol2; j++)
		{
			if (str[i] == (char)j)
			{
				lcounter++;
				break;
			}
		}
	}
}

void CountElements(int& lcount_a, int& lcount_o, char mystr[])
{
	for (int i = 0; i < strlen(mystr); i++)
	{
		if (mystr[i] == 'a') lcount_a++;
		if (mystr[i] == 'o') lcount_o++;
	}
}