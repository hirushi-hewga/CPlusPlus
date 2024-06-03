#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Fullname
{
private:
	string name;
	string surname;
	string lastname;
public:
	string GetName()
	{
		return name;
	}
	string GetSurname()
	{
		return surname;
	}
	string GetLastname()
	{
		return lastname;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	void SetSurname(string surname)
	{
		this->surname = surname;
	}
	void SetLastname(string lastname)
	{
		this->lastname = lastname;
	}
};




class Abonent
{
	static int count;
	Fullname fullname;
	int homePhone;
	int workPhone;
	int cellphone;
public:
	Abonent()
	{
		fullname.SetName("No name");
		fullname.SetSurname("No surname");
		fullname.SetLastname("No lastname");
		homePhone = 0;
		workPhone = 0;
		cellphone = 0;
		count++;
	}
	Abonent(string name, string surname, string lastname) : Abonent()
	{
		fullname.SetName(name);
		fullname.SetSurname(surname);
		fullname.SetLastname(lastname);
	}
	Abonent(string name, string surname, string lastname, int homePhone, int workPhone, int cellphone) : Abonent(name, surname, lastname)
	{
		this->homePhone = homePhone;
		this->workPhone = workPhone;
		this->cellphone = cellphone;
	}




	string GetName()
	{
		return fullname.GetName();
	}
	string GetSurname()
	{
		return fullname.GetSurname();
	}
	string GetLastname()
	{
		return fullname.GetLastname();
	}
	int GetHomePhone()
	{
		return homePhone;
	}
	int GetWorkPhone()
	{
		return workPhone;
	}
	int GetCellphone()
	{
		return cellphone;
	}
	void ShowFullName()
	{
		cout << "Full name : " << fullname.GetSurname() << ' ' << fullname.GetName() << ' ' << fullname.GetLastname() << endl;
	}
	void Show()
	{
		cout << endl;
		cout << "------- Abonent --------" << endl;
		cout << "Full name : " << fullname.GetSurname() << ' ' << fullname.GetName() << ' ' << fullname.GetLastname() << endl;
		cout << "Home phone : " << homePhone << endl;
		cout << "Work phone : " << workPhone << endl;
		cout << "Cellphone : " << cellphone << endl;
	}
	void SaveToFile()
	{
		ofstream out("Abonents.txt", ios_base::app);
		out << fullname.GetName();
		out << ":";
		out << fullname.GetSurname();
		out << ":";
		out << fullname.GetLastname();
		out << ":";
		out << homePhone;
		out << ":";
		out << workPhone;
		out << ":";
		out << cellphone;
		out << "|";
		out.close();
	}
	void FillFromFile(string nameB, string surnameB, string lastnameB, int homePhoneB, int workPhoneB, int cellphoneB)
	{
		fullname.SetName(nameB);
		fullname.SetSurname(surnameB);
		fullname.SetLastname(lastnameB);
		homePhone = homePhoneB;
		workPhone = workPhoneB;
		cellphone = cellphoneB;
	}
	void Copy(Abonent a)
	{
		fullname.SetName(a.fullname.GetName());
		fullname.SetSurname(a.fullname.GetSurname());
		fullname.SetLastname(a.fullname.GetLastname());
		homePhone = a.homePhone;
		workPhone = a.workPhone;
		cellphone = a.cellphone;
	}




	~Abonent()
	{
		count--;
	}
};




class AbonentList
{
	int count;
	Abonent* abonents;
public:
	AbonentList()
	{
		count = 0;
		abonents = nullptr;
	}




	void Delete()
	{
		if (count != 0)
		{
			int choice = 0;
			bool isValidData = true;
			while (choice < 1 || choice > count)
			{
				if (!isValidData) cout << "Error choice. Try again!" << endl;
				isValidData = false;
				for (int i = 0; i < count; i++)
				{
					cout << i + 1 << " - ";
					abonents[i].ShowFullName();
				}
				cout << "Choice abonent : ";
				cin >> choice;
			}
			choice--;
			Abonent* temp = new Abonent[count - 1];
			for (int i = 0; i < choice; i++)
			{
				temp[i] = abonents[i];
			}
			for (int i = choice; i < count - 1; i++)
			{
				temp[i] = abonents[i + 1];
			}
			delete[] abonents;
			abonents = temp;
			count--;
		}
		else cout << "Abonents not found." << endl;
	}
	void ShowByFullName()
	{
		if (count != 0)
		{
			int choice = 0;
			bool isValidData = true;
			while (choice < 1 || choice > 3)
			{
				if (!isValidData) cout << "Error choice. Try again!" << endl;
				isValidData = false;
				cout << "1 - Search by name" << endl;
				cout << "2 - Search by surname" << endl;
				cout << "3 - Search by lastname" << endl;
			}
			int showCount = 0;
			if (choice == 1)
			{
				string name;
				cout << "Enter name : " << endl;
				cin >> name;
				for (int i = 0; i < count; i++)
				{
					if (abonents[i].GetName() == name)
					{
						abonents[i].Show();
						showCount++;
					}
				}
			}
			if (choice == 2)
			{
				string surname;
				cout << "Enter surname : " << endl;
				cin >> surname;
				for (int i = 0; i < count; i++)
				{
					if (abonents[i].GetSurname() == surname)
					{
						abonents[i].Show();
						showCount++;
					}
				}
			}
			if (choice == 3)
			{
				string lastname;
				cout << "Enter lastname : " << endl;
				cin >> lastname;
				for (int i = 0; i < count; i++)
				{
					if (abonents[i].GetLastname() == lastname)
					{
						abonents[i].Show();
						showCount++;
					}
				}
			}
		}
		else cout << "Abonents not found." << endl;
	}
	void Show()
	{
		cout << endl;
		if (count != 0)
		{
			for (int i = 0; i < count; i++)
			{
				abonents[i].Show();
			}
		}
		else cout << "Abonents not found." << endl;
	}
	void Add()
	{
		cout << endl;
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > 2)
		{
			if (!isValidData) cout << "Error choice. Try again!" << endl;
			isValidData = false;
			cout << "1 - Total fill abonent" << endl;
			cout << "2 - Fill by full name" << endl;
			cout << "Enter your choice : ";
			cin >> choice;
		}
		Abonent* temp = new Abonent[count + 1];
		for (int i = 0; i < count; i++)
		{
			temp[i] = abonents[i];
		}
		if (choice == 2)
		{
			string name, surname, lastname;
			cout << "Enter name : "; cin >> name;
			cout << "Enter surname : "; cin >> surname;
			cout << "Enter lastname : "; cin >> lastname;
			temp[count] = Abonent(name, surname, lastname);
		}
		if (choice == 1)
		{
			string name, surname, lastname;
			int homePhone, workPhone, cellphone;
			cout << "Enter name : "; cin >> name;
			cout << "Enter surname : "; cin >> surname;
			cout << "Enter lastname : "; cin >> lastname;
			cout << "Enter homePhone : "; cin >> homePhone;
			cout << "Enter workPhone : "; cin >> workPhone;
			cout << "Enter cellphone : "; cin >> cellphone;
			temp[count] = Abonent(name, surname, lastname, homePhone, workPhone, cellphone);
		}
		if (abonents != nullptr) delete[] abonents;
		abonents = temp;
		count++;
		abonents[count - 1].SaveToFile();
	}
	void ReadFromFile()
	{
		ifstream in("Abonents.txt", ios_base::in);
		while (!in.eof())
		{
			char buffname[250], buffsurname[250], bufflastname[250], buffhomephone[250], buffworkphone[250], buffcellphone[250];
			in.getline(buffname, 250, ':');
			if (in.eof())break;
			in.getline(buffsurname, 250, ':');
			in.getline(bufflastname, 250, ':');
			in.getline(buffhomephone, 250, ':');
			in.getline(buffworkphone, 250, ':');
			in.getline(buffcellphone, 250, '|');
			string name(buffname);
			string surname(buffsurname);
			string lastname(bufflastname);
			int homephone = atoi(buffhomephone);
			int workphone = atoi(buffworkphone);
			int cellphone = atoi(buffcellphone);
			Abonent readHuman;
			readHuman.FillFromFile(name, surname, lastname, cellphone, workphone, cellphone);
			Abonent* temp = new Abonent[count + 1];
			for (int i = 0; i < count; i++)
			{
				temp[i].Copy(abonents[i]);
			}
			temp[count] = readHuman;
			delete abonents;
			abonents = temp;
			count++;
		}
	}




	~AbonentList()
	{
		delete[] abonents;
	}
};



int Abonent::count = 0;
int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 6)
	{
		if (!isValidData) cout << "Error choice. Try again!" << endl;
		isValidData = false;
		cout << "1 - Show all abonents" << endl;
		cout << "2 - Show abonent by fullname" << endl;
		cout << "3 - Add abonent" << endl;
		cout << "4 - Delete abonent" << endl;
		cout << "5 - Read from file" << endl;
		cout << "6 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { SHOW_ALL = 1, SHOW_BY_FULLNAME, ADD, DELETE, LOAD_FROM_FILE, EXIT };
int main()
{
	AbonentList abonents;
	bool isExit = false;
	while (!isExit)
	{
		cout << "========================" << endl;
		switch (Menu())
		{
		case MENU::SHOW_ALL: abonents.Show(); break;
		case MENU::SHOW_BY_FULLNAME: abonents.ShowByFullName(); break;
		case MENU::ADD: abonents.Add(); break;
		case MENU::DELETE: abonents.Delete(); break;
		case MENU::LOAD_FROM_FILE: abonents.ReadFromFile(); break;
		case MENU::EXIT: isExit = true; break;
		}
		cout << "========================" << endl;
	}
	cout << "Good bye." << endl;
}