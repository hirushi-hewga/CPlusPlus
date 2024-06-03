/*
#include <iostream>
#include <fstream>
using namespace std;

class Dot
{
	int x;
	int y;
	int z;
public:
	void Initialize()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	void CoordinateInit()
	{
		cout << "Enter coordinate x : "; cin >> x;
		cout << "Enter coordinate y : "; cin >> y;
		cout << "Enter coordinate z : "; cin >> z;
	}
	void CoordinateShow()
	{
		cout << "Coordinate x = " << x << endl;
		cout << "Coordinate y = " << y << endl;
		cout << "Coordinate z = " << z << endl;
	}
	void SetX(int value)
	{
		x = value;
	}
	void SetY(int value)
	{
		y = value;
	}
	void SetZ(int value)
	{
		z = value;
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	int GetZ()
	{
		return z;
	}
	void SaveToFile()
	{
		ofstream out("Coordinate.txt", ios_base::out);
		out << x;
		out << ":";
		out << y;
		out << ":";
		out << z;
		out << "|";
		out.close();
	}
	void FillFromFile(int xB, int yB, int zB)
	{
		x = xB;
		y = yB;
		z = zB;
	}
};

enum MENU { INIT = 1, SHOW, GETV, SETV, SAVE, LOAD, EXIT };

int Menu()
{
	int choice = 0;
	while (choice < 1 || choice > 7)
	{
		cout << "1 - Initialize coordinate" << endl;
		cout << "2 - Show coordinate" << endl;
		cout << "3 - Get value" << endl;
		cout << "4 - Set value" << endl;
		cout << "5 - Save to file" << endl;
		cout << "6 - Load from file" << endl;
		cout << "7 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}

void ReadFromFile(Dot& d)
{
	ifstream in("Coordinate.txt", ios_base::in);
	char buffX[250], buffY[250], buffZ[250];
	in.getline(buffX, 250, ':');
	in.getline(buffY, 250, ':');
	in.getline(buffZ, 250, '|');
	int x = atoi(buffX);
	int y = atoi(buffY);
	int z = atoi(buffZ);
	d.FillFromFile(x, y, z);
}

int GetValue(Dot d)
{
	int choice = 0;
	while (choice < 1 || choice > 3)
	{
		cout << "1 - Set x" << endl;
		cout << "2 - Set y" << endl;
		cout << "3 - Set z" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	if (choice == 1) return d.GetX();
	if (choice == 2) return d.GetY();
	if (choice == 3) return d.GetZ();
}

void SetValue(Dot& d)
{
	int choice = 0;
	while (choice < 1 || choice > 3)
	{
		cout << "1 - Get x" << endl;
		cout << "2 - Get y" << endl;
		cout << "3 - Get z" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	int value;
	cout << "Enter value to change : ";
	cin >> value;
	if (choice == 1) d.SetX(value);
	if (choice == 2) d.SetY(value);
	if (choice == 3) d.SetZ(value);
}
*/



//int main()
//{
	/*
	Dot dot;
	dot.Initialize();
	bool isExit = false;
	while (!isExit)
	{
		cout << endl;
		switch (Menu())
		{
		case MENU::INIT: dot.CoordinateInit(); break;
		case MENU::SHOW: dot.CoordinateShow(); break;
		case MENU::GETV: cout << GetValue(dot) << endl; break;
		case MENU::SETV: SetValue(dot); break;
		case MENU::SAVE: dot.SaveToFile(); break;
		case MENU::LOAD: ReadFromFile(dot); break;
		case MENU::EXIT: isExit = true;
		}
		cout << endl;
	}
	cout << "Good bye!" << endl;
	*/
	//}