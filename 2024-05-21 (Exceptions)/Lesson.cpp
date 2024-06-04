//#include <iostream>
////#include <exception>
//using namespace std;
//
//class List
//{
//	int size;
//public:
//	List() : size(0) {}
//	List(int size)
//	{
//		this->size = size > 0 ? size : 0;
//	}
//
//	int GetFromPosition(int pos)const
//	{
//		// 1 - code - collection is empty
//		if (size == 0) return 1;
//		// 2 - code - out of range
//		if (pos < 1 || pos > size) return 2;
//
//		return rand() % 10;
//	}
//};
//
//float Divide(float a, float b)
//{
//	// try catch throw
//	float res = 0;
//	if (b == 0)
//	{
//		cout << "You can`t divide by zero" << endl;
//		throw exception("Divide by zero");
//	}
//	else if (b == 2)
//	{
//		throw 404;
//	}
//	else if (b == 5)
//	{
//		throw "Divide by 5";
//	}
//	else
//	{
//		res = a / b;
//		cout << "Res in function = " << res << endl;
//		return res;
//	}
//}
//
//class PasswordInvalidException : public exception
//{
//public:
//	PasswordInvalidException(const char* ex) : exception(ex) {}
//};
//class PasswordSmallException : public exception
//{
//	int length;
//public:
//	PasswordSmallException(const char* ex, int length) : length(length), exception(ex) {}
//
//	void Message()const
//	{
//		cout << what() << endl;
//		cout << "Actual length : " << length << endl;
//	}
//};
//
//void Login(const char* login, const char* password)
//{
//	if (strlen(password) < 6)
//		throw PasswordSmallException("To small password");
//	if (!isalpha(login[0]) || !islower(login[0]))
//		throw exception("Login is invalid");
//	if (!isalpha(password[0]) || !islower(password[0]))
//		throw PasswordInvalidException("Password invalid");
//
//	cout << "Loading..........." << endl;
//}



//int main()
//{
	/*char login[100];
	char password[100];
	for (int i = 0; i < 5; i++)
	{
		cout << endl;
		cout << "===========================" << endl;
		cout << "Enter login : "; cin >> login;
		cout << "Enter password : "; cin >> password;

		try
		{
			Login(login, password);
		}
		catch (PasswordInvalidException ex)
		{
			cout << "Invalid password...... do something...." << endl;
			cout << ex.what() << endl;
			cout << "a-z, 0-9" << endl;
		}
		catch (PasswordSmallException ex)
		{
			cout << "Small password...... do something...." << endl;
			ex.Message();
			cout << "Length must be more than 6 symbols" << endl;
		}
		catch (...)
		{
			cout << "Unknown exception" << endl;
		}
	}*/



	/*float a, b;
	cout << "Enter a : ";
	cin >> a;
	cout << "Enter b : ";
	cin >> b;
	float res;
	try
	{
		res = Divide(a, b);
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	catch (int ex)
	{
		cout << ex << endl;
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}
	catch (...)
	{
		cout << "Unknown exception" << endl;
	}
	cout << "Continue........................" << endl;
	cout << "Continue........................" << endl;
	cout << "Continue........................" << endl;
	cout << "Continue........................" << endl;
	cout << "Res in main = " << res << endl;*/
	//}