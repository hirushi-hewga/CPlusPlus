#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void gotoxy(int p) {
	COORD coord;
	coord.X = p;
	coord.Y = p;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Point
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int x, int y)
	{
		this->x = x > 0 ? x : 0;
		this->y = y > 0 ? y : 0;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	void Show()const
	{
		cout << "x:" << x << " | y:" << y << endl;
	}
};

class Shape
{
public:
	virtual void Print()const = 0;
};

class Line_ : public Shape
{
	Point* point_1;
	Point* point_2;
public:
	Line_() : point_1(nullptr), point_2(nullptr) {}
	Line_(Point p1, Point p2)
	{
		point_1 = new Point(p1);
		point_2 = new Point(p2);
	}

	void LoadFromFile()
	{
		if (point_1 != nullptr) delete point_1;
		if (point_2 != nullptr) delete point_2;
		ifstream in("Line.txt", ios_base::in);
		char buffx1[50], buffy1[50], buffx2[50], buffy2[50];
		while (!in.eof())
		{
			in.getline(buffx1, 50, ':');
			if (in.eof()) break;
			in.getline(buffy1, 50, ':');
			in.getline(buffx2, 50, ':');
			in.getline(buffy2, 50, '|');
			NewLine(atoi(buffx1), atoi(buffy1), atof(buffx2), atof(buffy2));
		}
	}
	void SaveLineToFile()const
	{
		if (point_1 != nullptr && point_2 != nullptr)
		{
			ofstream out("Line.txt", ios_base::out);
			out << point_1->x;
			out << ':';
			out << point_1->y;
			out << ':';
			out << point_2->x;
			out << ':';
			out << point_2->y;
			out << '|';
			out.close();
		}
		else
		{
			system("cls");
			gotoxy(0);
			cout << "Rectangle points not found!" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
	}
	void NewLine(int x1, int y1, int x2, int y2)
	{
		if (point_1 != nullptr) delete point_1;
		if (point_2 != nullptr) delete point_2;
		point_1 = new Point(x1, y1);
		point_2 = new Point(x2, y2);
	}
	void Print()const override
	{
		if (point_1 != nullptr && point_2 != nullptr)
		{
			system("cls");
			gotoxy(0);
			cout << "======== Line ========" << endl;
			cout << "Point 1: "; point_1->Show();
			cout << "Point 2: "; point_2->Show();
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
		else
		{
			system("cls");
			gotoxy(0);
			cout << "Line not found!" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
	}

	~Line_()
	{
		delete point_1;
		delete point_2;
	}
};

class Rectangle_ : public Shape
{
	Point* angle;
	float width;
	float length;
public:
	Rectangle_() : width(0), length(0), angle(nullptr) {}
	Rectangle_(Point a, float w, float l)
	{
		angle = new Point(a);
		this->width = w > 0 ? w : 0;
		this->length = l > 0 ? l : 0;
	}

	void LoadFromFile()
	{
		if (angle != nullptr)
			delete angle;
		ifstream in("Rectangle.txt", ios_base::in);
		char buffx[50], buffy[50], buffw[50], buffl[50];
		while (!in.eof())
		{
			in.getline(buffx, 50, ':');
			if (in.eof()) break;
			in.getline(buffy, 50, ':');
			in.getline(buffw, 50, ':');
			in.getline(buffl, 50, '|');
			NewRectangle(atoi(buffx), atoi(buffy), atof(buffw), atof(buffl));
		}
	}
	void SaveRectangleToFile()const
	{
		if (angle != nullptr)
		{
			ofstream out("Rectangle.txt", ios_base::out);
			out << angle->x;
			out << ':';
			out << angle->y;
			out << ':';
			out << width;
			out << ':';
			out << length;
			out << '|';
			out.close();
		}
		else
		{
			system("cls");
			gotoxy(0);
			cout << "Rectangle points not found!" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
	}
	void NewRectangle(int x, int y, float w, float l)
	{
		if (angle != nullptr)
			delete angle;
		angle = new Point(x, y);
		this->width = w;
		this->length = l;
	}
	void Print()const override
	{
		if (angle != nullptr)
		{
			system("cls");
			gotoxy(0);
			cout << "======== Rectangle ========" << endl;
			cout << "Angle: "; angle->Show();
			cout << "Width : " << width << endl;
			cout << "Length : " << length << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
		else
		{
			system("cls");
			gotoxy(0);
			cout << "Rectangle not found!" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
	}

	~Rectangle_()
	{
		delete angle;
	}
};

class Polyline_ : public Shape
{
	Point* points;
	int pointCount;
public:
	Polyline_() : points(nullptr), pointCount(0) {}

	void LoadFromFile()
	{
		if (points != nullptr)
			delete[] points;
		pointCount = 0;
		ifstream in("Polyline.txt", ios_base::in);
		char buffx[50], buffy[50];
		while (!in.eof())
		{
			in.getline(buffx, 50, ':');
			if (in.eof()) break;
			in.getline(buffy, 50, '|');
			AddPoint(atoi(buffx), atoi(buffy));
		}
	}
	void SavePolylineToFile()const
	{
		if (points != nullptr)
		{
			ofstream out("Polyline.txt", ios_base::out);
			for (int i = 0; i < pointCount; i++)
			{
				out << points[i].x;
				out << ':';
				out << points[i].y;
				out << '|';
			}
			out.close();
		}
		else
		{
			system("cls");
			gotoxy(0);
			cout << "Polyline points not found!" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
	}
	void AddPoint(int x, int y)
	{
		Point* temp = new Point[pointCount + 1];
		for (int i = 0; i < pointCount; i++)
		{
			temp[i] = Point(points[i]);
		}
		temp[pointCount] = Point(x, y);
		delete[] points;
		points = temp;
		pointCount++;
	}
	void Print()const override
	{
		if (points != nullptr)
		{
			system("cls");
			gotoxy(0);
			cout << "======== Polyline ========" << endl;
			for (int i = 0; i < pointCount; i++)
			{
				cout << "Point_" << i + 1 << ": "; points[i].Show();
			}
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
		else
		{
			system("cls");
			gotoxy(0);
			cout << "Polyline points not found!" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
	}

	~Polyline_()
	{
		delete[] points;
	}
};



int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 13)
	{
		system("cls");
		gotoxy(0);
		if (!isValidData)
		{
			cout << "Error choice! Try again." << endl;
		}
		else isValidData = false;
		cout << endl;
		cout << "1 - Show line" << endl;
		cout << "2 - Show rectangle" << endl;
		cout << "3 - Show polyline" << endl;
		cout << "4 - Change line" << endl;
		cout << "5 - Change rectangle" << endl;
		cout << "6 - Add point to polyline" << endl;
		cout << "7 - Save line to file" << endl;
		cout << "8 - Save rectangle to file" << endl;
		cout << "9 - Save polyline to file" << endl;
		cout << "10 - Load line from file" << endl;
		cout << "11 - Load rectangle from file" << endl;
		cout << "12 - Load polyline from file" << endl;
		cout << "13 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { SHOW_LINE = 1, SHOW_RECTANGLE, SHOW_POLYLINE, CHANGE_LINE, CHANGE_RECTANGLE, ADD_POLYLINE, SAVE_LINE, SAVE_RECTANGLE, SAVE_POLYLINE, LOAD_LINE, LOAD_RECTANGLE, LOAD_POLYLINE, EXIT };
int main()
{
	char symbol;
	Line_ line;
	Rectangle_ rectangle;
	Polyline_ polyline;
	bool isExit = false;
	while (!isExit)
	{
		switch (Menu())
		{
		case MENU::SHOW_LINE: line.Print(); break;
		case MENU::SHOW_RECTANGLE: rectangle.Print(); break;
		case MENU::SHOW_POLYLINE: polyline.Print(); break;
		case MENU::CHANGE_LINE:
			system("cls");
			gotoxy(0);
			int x1, x2, y1, y2;
			cout << "Enter point_1 x : "; cin >> x1;
			cout << "Enter point_1 y : "; cin >> y1;
			cout << "Enter point_2 x : "; cin >> x2;
			cout << "Enter point_2 y : "; cin >> y2;
			line.NewLine(x1, y1, x2, y2);
			cout << endl;
			cout << "Line changed" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			symbol = _getch();
			break;
		case MENU::CHANGE_RECTANGLE:
			system("cls");
			gotoxy(0);
			int x_, y_;
			float w, l;
			cout << "Enter angle position x : "; cin >> x_;
			cout << "Enter angle position y : "; cin >> y_;
			cout << "Enter width : "; cin >> w;
			cout << "Enter length : "; cin >> l;
			rectangle.NewRectangle(x_, y_, w, l);
			cout << endl;
			cout << "Rectangle changed" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			symbol = _getch();
			break;
		case MENU::ADD_POLYLINE:
			system("cls");
			gotoxy(0);
			int x, y;
			cout << "Enter angle position x : "; cin >> x;
			cout << "Enter angle position y : "; cin >> y;
			polyline.AddPoint(x, y);
			cout << endl;
			cout << "Point added" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			symbol = _getch();
			break;
		case MENU::SAVE_LINE: line.SaveLineToFile(); break;
		case MENU::SAVE_RECTANGLE: rectangle.SaveRectangleToFile(); break;
		case MENU::SAVE_POLYLINE: polyline.SavePolylineToFile(); break;
		case MENU::LOAD_LINE: line.LoadFromFile(); break;
		case MENU::LOAD_RECTANGLE: rectangle.LoadFromFile(); break;
		case MENU::LOAD_POLYLINE: polyline.LoadFromFile(); break;
		case MENU::EXIT: isExit = true;
		}
	}
	system("cls");
	cout << "Good bye." << endl;
}