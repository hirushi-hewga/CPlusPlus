#include <iostream>
using namespace std;

struct Point
{
	int x;
	int y;
};

class Student
{
private:
	string name;
	int age;
	int* marks;
	int marksCount;
public:
	Student()
	{
		name = "";
		age = 0;
		marks = nullptr;
		marksCount = 0;
	}
	Student(string name, int age, int year)
	{
		this->name = name;
		this->age = age;
		this->marks = nullptr;
		this->marksCount = 0;

		cout << "Paramerized Constructor [" << name << "]...\n";
	}
	Student(const Student& other)
	{
		this->name = other.name;
		this->age = other.age;
		this->marksCount = other.marksCount;
		//copy pointer = address
		//this->marks = other.marks;
		this->marks = new int[other.marksCount];
		for (int i = 0; i < other.marksCount; i++)
		{
			cout << "";
		}
	}
	~Student()
	{
		if (marks != nullptr)
			delete[] marks;
		cout << "Destructor [" << name << "]...\n";
	}


	void Print() const
	{
		cout << "-------- STUDENT [" << name << "] ---------\n";
		cout << "Age: " << age << endl;
		cout << "Marks: ";
		for (size_t i = 0; i < marksCount; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;
	}

	void AddMark(int value)
	{
		int* new_arr = new int[marksCount + 1];
		for (size_t i = 0; i < marksCount; ++i)
		{
			new_arr[i] = marks[i];
		}
		new_arr[marksCount] = value;
		if (marks != nullptr)
			delete[] marks;
		marks = new_arr;

		++marksCount;
	}

};



struct Carriage
{
	int number;
	int places;
	int passangers;
};
class Train
{
	string model;
	int countCarriager;
	Carriage* carriages;
};

//int main()
//{
	//int a;
	//int b = 10;
	////implicit
	//int c = 3.33;
	////cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;

	//int numbers[2];
	//cout << numbers[0] << endl;
	//numbers[0] += 2;
	//cout << numbers[0] << endl;

	//int sum;
	//for (int i = 0; i < 10; i++)
	//{
	//	sum += i;
	//}cout << "Summa = " << sum << endl;

	/*int number = 0;
	int value(42);
	int size{ 33 };
	double pi{ 3.14 };
	cout << number << endl;
	cout << value << endl;
	cout << size << endl;
	cout << pi << endl;

	int answear{ 15 };
	const float goodTemp{ 36.6 };
	int grades[4]{ 1,4,5,12 };
	int matrix[2][2]{ 1,2,3,4 };

	int* ptr{ nullptr };
	int& la{ answear };
	Point point{ 10,5 };*/



	/*Student testSt;
	Student st("Viktor", 15, 2010);

	st.AddMark(8);
	st.AddMark(7);
	st.AddMark(11);
	st.AddMark(10);

	st.Print();

	{
		Student st3(st);
		st3.Print();
	}

	st.Print();*/
	//}