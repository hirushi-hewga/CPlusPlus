#include <iostream>
#include <Windows.h>
#include <chrono>
#include <conio.h>
using namespace std;

enum ConsoleColors {
	BLACK = 0,
	DARKBLUE = FOREGROUND_BLUE,
	DARKGREEN = FOREGROUND_GREEN,
	DARKCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
	DARKRED = FOREGROUND_RED,
	DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
	DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
	DARKGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	GRAY = FOREGROUND_INTENSITY,
	BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
	GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
	CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
	YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
};
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void SetCursorPosition(int x, int y)
{
	COORD pos = { x, y };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, pos);
}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

enum DIRECTION { LEFT, RIGHT, UP, DOWN };
enum HERO { NO_HERO, BATMAN, JOKER, HALK };

class Hero
{
	HERO hero;
	int w, h;
	COORD position;
	char symbol;
	DIRECTION dir;

	void PrintSymbols(int count, ConsoleColors color, char symbol)const
	{
		SetConsoleTextAttribute(hConsole, color);
		for (int i = 0; i < count * 2; i++)
		{
			cout << symbol;
		}
	}
	void PrintSymbols(int count)const
	{
		for (int i = 0; i < count * 2; i++)
		{
			cout << ' ';
		}
	}
public:
	Hero() : hero(NO_HERO), h(8), w(16), position({ 1, 1 }), symbol((char)178), dir(RIGHT) {}

	void PrintBord()const
	{
		COORD pos{ 0, 0 };
		SetCursorPosition(pos.X, pos.Y);
		cout << (char)201;
		for (int i = 0; i < 54; i++)
			cout << (char)205;
		cout << (char)187;
		for (int i = 0; i < 24; i++)
		{
			pos.Y++;
			SetCursorPosition(pos.X, pos.Y);
			cout << (char)186;
			SetCursorPosition(pos.X + 55, pos.Y);
			cout << (char)186;
		}
		pos.Y++;
		SetCursorPosition(pos.X, pos.Y);
		cout << (char)200;
		for (int i = 0; i < 54; i++)
			cout << (char)205;
		cout << (char)188;
	}
	void MarkBatman()const
	{
		COORD pos{ position.X, position.Y };
		SetCursorPosition(pos.X, pos.Y);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(6);
		PrintSymbols(1, DARKRED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(8, DARKRED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(1, RED, symbol);
		PrintSymbols(4, DARKRED, symbol);
		PrintSymbols(1, RED, symbol);
		PrintSymbols(1, DARKRED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(2, RED, symbol);
		PrintSymbols(2, DARKRED, symbol);
		PrintSymbols(2, RED, symbol);
		PrintSymbols(1, DARKRED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(2, DARKGRAY, symbol);
		PrintSymbols(2, RED, symbol);
		PrintSymbols(2, DARKGRAY, symbol);
		PrintSymbols(1, DARKRED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(6, RED, symbol);
		PrintSymbols(1, DARKRED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(2, RED, symbol);
		PrintSymbols(2, DARKGRAY, symbol);
		PrintSymbols(2, RED, symbol);
		PrintSymbols(1, DARKRED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(4, RED, symbol);
		PrintSymbols(1, DARKRED, symbol);
	}
	void PrintBatman()const
	{
		COORD pos{ position.X, position.Y };
		SetCursorPosition(pos.X, pos.Y);
		PrintSymbols(1, DARKBLUE, symbol);
		PrintSymbols(6);
		PrintSymbols(1, DARKBLUE, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(8, DARKBLUE, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKBLUE, symbol);
		PrintSymbols(1, BLACK, symbol);
		PrintSymbols(4, DARKBLUE, symbol);
		PrintSymbols(1, BLACK, symbol);
		PrintSymbols(1, DARKBLUE, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKBLUE, symbol);
		PrintSymbols(2, BLACK, symbol);
		PrintSymbols(2, DARKBLUE, symbol);
		PrintSymbols(2, BLACK, symbol);
		PrintSymbols(1, DARKBLUE, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKBLUE, symbol);
		PrintSymbols(2, WHITE, symbol);
		PrintSymbols(2, BLACK, symbol);
		PrintSymbols(2, WHITE, symbol);
		PrintSymbols(1, DARKBLUE, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKBLUE, symbol);
		PrintSymbols(6, BLACK, symbol);
		PrintSymbols(1, DARKBLUE, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKBLUE, symbol);
		PrintSymbols(2, YELLOW, symbol);
		PrintSymbols(2, WHITE, symbol);
		PrintSymbols(2, YELLOW, symbol);
		PrintSymbols(1, DARKBLUE, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1);
		PrintSymbols(1, DARKBLUE, symbol);
		PrintSymbols(4, YELLOW, symbol);
		PrintSymbols(1, DARKBLUE, symbol);
	}
	void MarkJoker()const
	{
		COORD pos{ position.X, position.Y };
		SetCursorPosition(pos.X, pos.Y);
		PrintSymbols(1);
		PrintSymbols(6, DARKRED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(8, DARKRED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(2, RED, symbol);
		PrintSymbols(2, DARKRED, symbol);
		PrintSymbols(2, RED, symbol);
		PrintSymbols(1, DARKRED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, RED, symbol);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(4, RED, symbol);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(1, RED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, RED, symbol);
		PrintSymbols(1, BLACK, symbol);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(2, RED, symbol);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(1, BLACK, symbol);
		PrintSymbols(1, RED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(8, RED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, RED, symbol);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(4, BLACK, symbol);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(1, RED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1);
		PrintSymbols(1, RED, symbol);
		PrintSymbols(4, DARKRED, symbol);
		PrintSymbols(1, RED, symbol);
	}
	void PrintJoker()const
	{
		COORD pos{ position.X, position.Y };
		SetCursorPosition(pos.X, pos.Y);
		PrintSymbols(1);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(1, GREEN, symbol);
		PrintSymbols(2, DARKGREEN, symbol);
		PrintSymbols(1, GREEN, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(1, GREEN, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(2, GREEN, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(1, GREEN, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, GREEN, symbol);
		PrintSymbols(2, WHITE, symbol);
		PrintSymbols(2, DARKGREEN, symbol);
		PrintSymbols(2, WHITE, symbol);
		PrintSymbols(1, GREEN, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, WHITE, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(4, WHITE, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(1, WHITE, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, WHITE, symbol);
		PrintSymbols(1, BLACK, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(2, WHITE, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(1, BLACK, symbol);
		PrintSymbols(1, WHITE, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(8, WHITE, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, WHITE, symbol);
		PrintSymbols(1, RED, symbol);
		PrintSymbols(4, BLACK, symbol);
		PrintSymbols(1, RED, symbol);
		PrintSymbols(1, WHITE, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1);
		PrintSymbols(1, WHITE, symbol);
		PrintSymbols(4, RED, symbol);
		PrintSymbols(1, WHITE, symbol);
	}
	void MarkHalk()const
	{
		COORD pos{ position.X, position.Y };
		SetCursorPosition(pos.X, pos.Y);
		PrintSymbols(1);
		PrintSymbols(6, DARKRED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(8, DARKRED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(1, RED, symbol);
		PrintSymbols(1, DARKRED, symbol);
		PrintSymbols(1, RED, symbol);
		PrintSymbols(2, DARKRED, symbol);
		PrintSymbols(1, RED, symbol);
		PrintSymbols(1, DARKRED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, RED, symbol);
		PrintSymbols(2, DARKRED, symbol);
		PrintSymbols(2, RED, symbol);
		PrintSymbols(2, DARKRED, symbol);
		PrintSymbols(1, RED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, RED, symbol);
		PrintSymbols(1, DARKGRAY, symbol);
		PrintSymbols(4, RED, symbol);
		PrintSymbols(1, DARKGRAY, symbol);
		PrintSymbols(1, RED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(3, RED, symbol);
		PrintSymbols(2, DARKGRAY, symbol);
		PrintSymbols(3, RED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(3, RED, symbol);
		PrintSymbols(2, BLACK, symbol);
		PrintSymbols(3, RED, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1);
		PrintSymbols(6, RED, symbol);
	}
	void PrintHalk()const
	{
		COORD pos{ position.X, position.Y };
		SetCursorPosition(pos.X, pos.Y);
		PrintSymbols(1);
		PrintSymbols(6, BLACK, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(8, BLACK, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, BLACK, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(1, BLACK, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(2, BLACK, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(1, BLACK, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(2, BLACK, symbol);
		PrintSymbols(1, GREEN, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(2, BLACK, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(1, WHITE, symbol);
		PrintSymbols(4, GREEN, symbol);
		PrintSymbols(1, WHITE, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(2, GREEN, symbol);
		PrintSymbols(2, WHITE, symbol);
		PrintSymbols(2, GREEN, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(2, GREEN, symbol);
		PrintSymbols(2, BLACK, symbol);
		PrintSymbols(2, GREEN, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
		SetCursorPosition(pos.X, ++pos.Y);
		PrintSymbols(1);
		PrintSymbols(1, DARKGREEN, symbol);
		PrintSymbols(4, GREEN, symbol);
		PrintSymbols(1, DARKGREEN, symbol);
	}
	void ClearHero()const
	{
		for (int i = 0; i < h; i++)
		{
			SetCursorPosition(position.X, position.Y + i);
			for (int i = 0; i < w; i++)
			{
				cout << ' ';
			}
		}
	}
	void ChoiceHero()
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > 3)
		{
			cout << "1 - Batman" << endl;
			cout << "2 - Joker" << endl;
			cout << "3 - Halk" << endl;
			cout << endl;
			if (!isValidData)
			{
				cout << "Error choice! Try again." << endl;
				cout << endl;
			}
			else isValidData = false;
			cout << "Enter your choice : ";
			cin >> choice;
		}
		system("cls");
		switch (choice)
		{
		case HERO::BATMAN: hero = BATMAN; break;
		case HERO::JOKER: hero = JOKER; break;
		case HERO::HALK: hero = HALK;
		}
	}
	void Move()
	{
		ClearHero();
		bool isMoved = false;
		switch (dir)
		{
		case LEFT: isMoved = MoveLeft(); break;
		case RIGHT: isMoved = MoveRight(); break;
		case UP: isMoved = MoveUp(); break;
		case DOWN: isMoved = MoveDown();
		}
		switch (hero)
		{
		case HERO::BATMAN: isMoved ? PrintBatman() : MarkBatman(); break;
		case HERO::JOKER: isMoved ? PrintJoker() : MarkJoker(); break;
		case HERO::HALK: isMoved ? PrintHalk() : MarkHalk();
		}
	}
	bool IsValidPosition(int x, int y)const
	{
		return x > 0 && y > 0 && x + w - 1 < 55 && y + h - 1 < 25;
	}
	bool MoveRight()
	{
		if (IsValidPosition(position.X + 1, position.Y))
		{
			position.X++;
			return true;
		}
		return false;
	}
	bool MoveLeft()
	{
		if (IsValidPosition(position.X - 1, position.Y))
		{
			position.X--;
			return true;
		}
		return false;
	}
	bool MoveUp()
	{
		if (IsValidPosition(position.X, position.Y - 1))
		{
			position.Y--;
			return true;
		}
		return false;
	}
	bool MoveDown()
	{
		if (IsValidPosition(position.X, position.Y + 1))
		{
			position.Y++;
			return true;
		}
		return false;
	}
	void ChangeDirection(DIRECTION dir)
	{
		this->dir = dir;
	}
};



int main()
{
	Hero hero;
	hero.ChoiceHero();

	hidecursor();
	hero.PrintBord();

	time_t interval = 100;
	time_t start = clock();

	while (true)
	{
		if (clock() >= start + interval)
		{
			hero.Move();
			start = clock();
		}
		if (_kbhit())
		{
			int key = _getch();

			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 77: hero.ChangeDirection(RIGHT); break;
				case 80: hero.ChangeDirection(DOWN); break;
				case 72: hero.ChangeDirection(UP); break;
				case 75: hero.ChangeDirection(LEFT); break;
				}
			}
		}
	}
}