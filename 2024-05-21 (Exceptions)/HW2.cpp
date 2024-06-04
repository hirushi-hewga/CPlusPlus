#include <iostream>
#include <stdlib.h>
using namespace std;



int CharToInt_(const char* s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (!isdigit(s[i]))
			throw exception("Numerical error");
	}
	long long  number = atoll(s);
	if (number > INT_MAX || number < INT_MIN)
		throw overflow_error("out of range");
	return atoi(s);
}

int main()
{
	try
	{
		int a = CharToInt_("2147483647a");
		cout << a << endl;
	}
	catch (overflow_error ex)
	{
		cout << endl;
		cout << ex.what() << endl;
		cout << endl;
	}
	catch (exception ex)
	{
		cout << endl;
		cout << ex.what() << endl;
		cout << endl;
	}
	catch (...)
	{
		cout << "\nUnknown exception\n" << endl;
	}
}