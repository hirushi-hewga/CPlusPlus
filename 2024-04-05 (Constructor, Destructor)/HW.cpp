#include <iostream>
#include <conio.h>
using namespace std;

struct Coord
{
	int x;
	int y;
};

class Rectangle
{
	int height;
	int width;
	char symbol;
	Coord coord;
public:
	Rectangle()
	{
		cout << "-- Construct rectangle --" << endl;
		height = 0;
		width = 0;
		symbol = '0';
		coord.x = 0;
		coord.y = 0;
	}
	Rectangle(int size)
	{
		cout << "-- Construct rectangle --" << endl;
		height = size;
		width = size;
		symbol = '0';
		coord.x = 0;
		coord.y = 0;
	}
	Rectangle(int height, int width)
	{
		cout << "-- Construct rectangle --" << endl;
		this->height = height;
		this->width = width;
		symbol = '0';
		coord.x = 0;
		coord.y = 0;
	}
	void ShowData()
	{
		cout << "-- Rectangle Data --" << endl;
		cout << "Height : " << height << endl;
		cout << "Width : " << width << endl;
		cout << "Symbol : " << symbol << endl;
		cout << "Coord x : " << coord.x << endl;
		cout << "Coord y : " << coord.y << endl;
	}
	void Show()
	{
		cout << endl;

		for (int i = 0; i < coord.y; i++) cout << endl;

		for (int i = 0; i < height; i++)
		{
			for (int i = 0; i < coord.x; i++) cout << ' ';
			for (int i = 0; i < width; i++) cout << symbol << ' ';
			cout << endl;
		}

		cout << endl;
	}
	void SetSize(int height, int width)
	{
		this->height = height;
		this->width = width;
	}
	void SetCoord(int x, int y)
	{
		coord.x = x;
		coord.y = y;
	}
	void SetSymbol(char symbol)
	{
		this->symbol = symbol;
	}
	~Rectangle()
	{
		cout << "-- Destruct rectangle --" << endl;
	}
};



void SetRectangleSymbol(Rectangle& rec)
{
	cout << "Enter new rectangle symbol : ";
	char symbol = _getch();
	cout << endl;
	rec.SetSymbol(symbol);
}
void SetRectangleCoord(Rectangle& rec)
{
	int x = -1;
	int y = -1;
	bool isValidData = true;
	while (x < 0 || y < 0)
	{
		if (!isValidData) cout << "Error data. Try again!" << endl;
		if (isValidData) isValidData = false;
		cout << "Enter x coord : ";
		cin >> x;
		cout << "Enter y coord : ";
		cin >> y;
	}
	rec.SetCoord(x, y);
}
void SetRectangleSize(Rectangle& rec)
{
	int height = -1;
	int width = -1;
	bool isValidData = true;
	while (height < 0 || width < 0)
	{
		if (!isValidData) cout << "Error data. Try again!" << endl;
		if (isValidData) isValidData = false;
		cout << "Enter height : ";
		cin >> height;
		cout << "Enter width : ";
		cin >> width;
	}
	rec.SetSize(height, width);
}
void CreateRectangle(Rectangle& rec)
{
	int choice = 0;
	while (choice < 1 || choice > 3)
	{
		cout << endl;
		cout << "1 - create default rectangle" << endl;
		cout << "2 - create rectangle by size" << endl;
		cout << "3 - create rectangle by height and width" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	cout << endl;
	if (choice == 1)
	{
		Rectangle new_rec;
		rec = new_rec;
	}
	if (choice == 2)
	{
		int size = -1;
		bool isValidData = true;
		while (size < 0)
		{
			if (!isValidData) cout << "Error data. Try again!" << endl;
			if (isValidData) isValidData = false;
			cout << "Enter size : ";
			cin >> size;
		}
		Rectangle new_rec(size);
		rec = new_rec;
	}
	if (choice == 3)
	{
		int height = -1;
		int width = -1;
		bool isValidData = true;
		while (height < 0 || width < 0)
		{
			if (!isValidData) cout << "Error data. Try again!" << endl;
			if (isValidData) isValidData = false;
			cout << "Enter height : ";
			cin >> height;
			cout << "Enter width : ";
			cin >> width;
		}
		Rectangle new_rec(height, width);
		rec = new_rec;
	}
}
int Menu()
{
	int choice = 0;
	while (choice < 1 || choice > 7)
	{
		cout << endl;
		cout << "1 - Create new rectangle" << endl;
		cout << "2 - Show rectangle" << endl;
		cout << "3 - Show rectangle data" << endl;
		cout << "4 - Set rectangle size" << endl;
		cout << "5 - Set rectangle coord" << endl;
		cout << "6 - Set rectangle symbol" << endl;
		cout << "7 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}

enum MENU { CREATE = 1, SHOW_RECTANGLE, SHOW_RECTANGLE_DATA, SET_SIZE, SET_COORD, SET_SYMBOL, EXIT };

int main()
{
	Rectangle rectangle;
	bool isExit = false;
	while (!isExit)
	{
		cout << "------------------------" << endl;
		switch (Menu())
		{
		case MENU::CREATE:				CreateRectangle(rectangle);		break;
		case MENU::SHOW_RECTANGLE:		rectangle.Show();				break;
		case MENU::SHOW_RECTANGLE_DATA: rectangle.ShowData();			break;
		case MENU::SET_SIZE:			SetRectangleSize(rectangle);	break;
		case MENU::SET_COORD:			SetRectangleCoord(rectangle);	break;
		case MENU::SET_SYMBOL:			SetRectangleSymbol(rectangle);	break;
		case MENU::EXIT:				isExit = true;
		}
		cout << "------------------------" << endl;
	}
	cout << "Good bye." << endl;
}