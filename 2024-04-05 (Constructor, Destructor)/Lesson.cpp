//#include <iostream>
//using namespace std;
//
//class Student
//{
//	string name;
//	int age;
//	int countMarks;
//	int* marks;
//	int averageMark;
//	void SetAverage()
//	{
//		int summa = 0;
//		for (int i = 0; i < countMarks; i++)
//		{
//			summa += marks[i];
//		}
//		averageMark = (float)summa / countMarks;
//	}
//public:
//	Student() // constructor
//	{
//		cout << "Constructor........" << endl;
//		name = "None";
//		age = 0;
//		countMarks = 0;
//		marks = nullptr;
//		averageMark = 0;
//	}
//	Student(string name, int age)
//	{
//		cout << "Constructor........" << endl;
//		this->name = name;
//		this->age = age;
//		countMarks = 0;
//		marks = nullptr;
//		averageMark = 0;
//	}
//	/*void Initialize()
//	{
//		name = "None";
//		age = 0;
//		countMarks = 0;
//		marks = nullptr;
//		averageMark = 0;
//	}*/
//	/*void Initialize(string name, int age)
//	{
//		this->name = name;
//		this->age = age;
//		countMarks = 0;
//		marks = nullptr;
//		averageMark = 0;
//	}*/
//	void Show()
//	{
//		cout << "Name : " << name << endl;
//		cout << "Age : " << age << endl;
//		cout << "Count marks : " << countMarks << endl;
//		cout << "Marks : ";
//		for (int i = 0; i < countMarks; i++)
//		{
//			cout << marks[i] << ' ';
//		}
//		cout << endl;
//		cout << "AverageMarks : " << averageMark << endl;
//		cout << endl;
//	}
//	void AddMark(int mark)
//	{
//		int* temp = new int[countMarks + 1];
//		for (int i = 0; i < countMarks; i++)
//		{
//			temp[i] = marks[i];
//		}
//		temp[countMarks] = mark;
//		if (marks != nullptr)
//			delete[] marks;
//		marks = temp;
//		countMarks++;
//		SetAverage();
//	}
//	void SetName(string name)
//	{
//		this->name = name;
//	}
//	void SetAge(int age)
//	{
//		this->age = age;
//	}
//	void DeleteMarks()
//	{
//		if (marks != nullptr)
//			delete[] marks;
//	}
//	~Student() // destructor
//	{
//		cout << "Destructor" << name << endl;
//		DeleteMarks();
//	}
//};




//int main()
//{
	//Student st1;
	//st1.SetName("Vasia");
	//st1.Show();

	//st1.Initialize("Bob", 25);
	//st1.Show();

	//st1.AddMark(12);
	//st1.AddMark(11);
	//st1.AddMark(9);
	//st1.AddMark(3);

	//st1.SetName("Sasha");
	//st1.SetAge(33);

	//st1.Show();

	//st1.DeleteMarks();

	//Student st2("Mark", 12);
	//st2.SetName("Olga");
	//st2.Show();
	//st2.AddMark(12);
	//st2.AddMark(11);
	//st2.AddMark(9);
	//st2.AddMark(3);
	//st2.Show();
//}