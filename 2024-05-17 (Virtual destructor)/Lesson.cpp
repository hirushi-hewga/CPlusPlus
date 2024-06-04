#include <iostream>
using namespace std;

class Student
{
	string name;
	string spetialization;
	int* marks;
	int markCount;
public:
	Student() : spetialization("no spetialization"), name("no name"), marks(nullptr), markCount(0) {}
	Student(string name, string spetialization) : name(name), spetialization(spetialization)
	{
		markCount = rand() % 10 + 1;
		marks = new int[markCount];
		for (int i = 0; i < markCount; i++)
		{
			marks[i] = rand() % 4 + 9;
		}
	}
	virtual void Print()const
	{
		cout << "Student : " << name << endl;
		cout << "Spetialization : " << spetialization << endl;
		cout << "Marks : ";
		for (int i = 0; i < markCount; i++)
		{
			cout << marks[i] << ' ';
		}
		cout << "\n_________________________\n";
	}

	virtual ~Student()
	{
		if (marks != nullptr)
			delete[] marks;
	}
};

class Aspirant : public Student
{
	string* subjects;
	int subjectCount;
public:
	Aspirant() : subjects(nullptr), Student() {}
	Aspirant(string name, string sp, initializer_list<string> sub) : Student(name, sp)
	{
		this->subjectCount = sub.size();
		subjects = new string[subjectCount];

		int i = 0;
		for (string s : sub)
		{
			this->subjects[i] = s;
			i++;
		}
	}

	void Print()const override
	{
		Student::Print();
		cout << "Subject : ";
		for (int i = 0; i < subjectCount; i++)
		{
			cout << subjects[i] << "  -  ";
		}
		cout << endl;
	}

	~Aspirant()
	{
		if (subjects != nullptr)
			delete[] subjects;
	}
};



int main()
{
	srand(time(NULL));
	Student st("Artem", "Programmer");
	st.Print();

	Aspirant asp("Olga", "Managment", { "Work with resourses", "Salles", "Test theme" });
	asp.Print();


	cout << "\n-----------------------------\n";
	Student* group[3]
	{
		new Student("Artem", "Programmer"),
		new Aspirant("Olga", "Managment", { "Work with resourses", "Salles", "Test theme"}),
		new Aspirant("Viktor", "UA/UX", { "Main window", "User experiance" })
	};

	for (int i = 0; i < 3; i++)
	{
		group[i]->Print();
		delete group[i];
	}
}