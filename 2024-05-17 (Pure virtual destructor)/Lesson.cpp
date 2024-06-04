#include <iostream>
using namespace std;

class Person // abstract class
{
	string name;
public:
	Person() : name("no name") {}
	Person(string name) : name(name) {}
	virtual void Print()const
	{
		cout << "Student : " << name << endl;
		cout << "\n_________________________\n";
	}

	virtual ~Person() = 0 {} // pure virtual destructor
};

class Aspirant : public Person
{
	string* subjects;
	int subjectCount;
public:
	Aspirant() : subjects(nullptr), Person() {}
	Aspirant(string name, initializer_list<string> sub) : Person(name)
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
		Person::Print();
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



//int main()
//{
	//srand(time(NULL));
	////Person st("Artem");
	////st.Print();

	////asp.Print();


	//cout << "\n-----------------------------\n";
	//Person* group[3]
	//{
	//	//new Person("Artem"),
	//	new Aspirant("Olga", { "Work with resourses", "Salles", "Test theme"}),
	//	new Aspirant("Viktor", { "Main window", "User experiance" })
	//};

	//for (int i = 0; i < 2; i++)
	//{
	//	group[i]->Print();
	//	delete group[i];
	//}
//}