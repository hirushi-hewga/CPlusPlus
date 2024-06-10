//#include "Console.h"
//
//enum DIRECTION { LEFT, RIGHT, UP, DOWN };
//
//class Hero
//{
//	string name;
//	int hp;
//	int h, w;
//	COORD position;
//	char symbol;
//	DIRECTION dir;
//
//	void Print(char filler)const
//	{
//		for (int i = 0; i < h; i++)
//		{
//			SetCursorPosition(position.X, position.Y + i);
//			for (int i = 0; i < w; i++)
//			{
//				cout << filler;
//			}
//			cout << endl;
//		}
//	}
//public:
//	Hero() : name("no name"), hp(100), h(1), w(1), position({0, 0}), symbol('#'), dir(RIGHT) {}
//	Hero(string name, int h, int w, char s) : name(name), hp(100), h(h), w(w), position({ 0, 0 }), symbol(s), dir(RIGHT)
//	{
//		this->h = h >= 1 ? h : 1;
//		this->w = w >= 1 ? w : 1;
//	}
//
//	void PrintHero()const
//	{
//		SetConsoleTextAttribute(hConsole, ConsoleColors::GREEN);
//		Print(symbol);
//	}
//	void ClearHero()const
//	{
//		Print(' ');
//	}
//	void MarkHero()const
//	{
//		SetConsoleTextAttribute(hConsole, ConsoleColors::RED);
//		Print(symbol);
//	}
//	void ShowInfo()const
//	{
//		cout << "-------- Player [ " << name << " ] . HP : " << hp << " --------" << endl;
//	}
//	void SetPosition(int x, int y)
//	{
//		position.X = x >= 0 ? x : 0;
//		position.Y = y >= 0 ? y : 0;
//	}
//	void Move()
//	{
//		ClearHero();
//		bool isMoved = false;
//		switch (dir)
//		{
//		case LEFT: isMoved = MoveLeft(); break;
//		case RIGHT: isMoved = MoveRight(); break;
//		case UP: isMoved = MoveUp(); break;
//		case DOWN: isMoved = MoveDown();
//		}
//		isMoved ? PrintHero() : MarkHero();
//	}
//	void ChangeDirection(DIRECTION dir)
//	{
//		this->dir = dir;
//	}
//	bool IsValidPosition(int x, int y)const
//	{
//		return x >= 0 && y >= 0;
//	}
//	bool MoveRight()
//	{
//		if (IsValidPosition(position.X + 1, position.Y))
//		{
//			position.X++;
//			return true;
//		}
//		return false;
//	}
//	bool MoveLeft()
//	{
//		if (IsValidPosition(position.X - 1, position.Y))
//		{
//			position.X--;
//			return true;
//		}
//		return false;
//	}
//	bool MoveUp()
//	{
//		if (IsValidPosition(position.X, position.Y - 1))
//		{
//			position.Y--;
//			return true;
//		}
//		return false;
//	}
//	bool MoveDown()
//	{
//		if (IsValidPosition(position.X, position.Y + 1))
//		{
//			position.Y++;
//			return true;
//		}
//		return false;
//	}
//};



//int main()
//{
//	hidecursor();
//
//	Hero hero("King", 3, 4, '#');
//	hero.ShowInfo();
//	hero.SetPosition(10, 10);
//	hero.PrintHero();
//	time_t interval = 500;
//	time_t start = clock();
//
//	while (true)
//	{
//		if (clock() >= start + 500)
//		{
//			hero.Move();
//			start = clock();
//		}
//		if (_kbhit())
//		{
//			int key = _getch();
//
//			if (key == 224)
//			{
//				key = _getch();
//				//cout << key << endl;
//				switch (key)
//				{
//				case 77: hero.ChangeDirection(RIGHT); break;
//				case 80: hero.ChangeDirection(DOWN); break;
//				case 72: hero.ChangeDirection(UP); break;
//				case 75: hero.ChangeDirection(LEFT); break;
//				}
//			}
//		}
//	}
//}