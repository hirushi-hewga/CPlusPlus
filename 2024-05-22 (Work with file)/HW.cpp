#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

class Carriage
{
	int number;
	int placeCount;
	int passangerCount;
public:
	Carriage() : number(0), placeCount(0), passangerCount(0) {}
	Carriage(int number, int placeCount, int passangerCount) : number(number), placeCount(placeCount), passangerCount(passangerCount) {}

	void DecreaseNumber() { number--; }
	void Show()const
	{
		cout << "-------- Carriage [" << number << "] --------" << endl;
		cout << "Place count : " << placeCount << endl;
		cout << "PassangerCount : " << passangerCount << endl;
		cout << endl;
	}

	friend ofstream& operator <<(ofstream& out, const Carriage& other);
	friend ifstream& operator >>(ifstream& in, Carriage& other);
};
ofstream& operator <<(ofstream& out, const Carriage& other)
{
	out << other.number << ' ' << other.placeCount << ' ' << other.passangerCount << endl;
	return out;
}
ifstream& operator >>(ifstream& in, Carriage& other)
{
	in >> other.number >> other.placeCount >> other.passangerCount;
	return in;
}



class Train
{
	string model;
	Carriage* carriages;
	int carriageCount;
public:
	Train() = delete;
	Train(string model) : model(model), carriages(nullptr), carriageCount(0) {}

	void Show()
	{
		system("cls");
		cout << "======== Train : " << model << " ========" << endl;
		if (carriages != nullptr)
		{
			for (int i = 0; i < carriageCount; i++)
			{
				carriages[i].Show();
			}
		}
		else
		{
			cout << "Carriages not found" << endl;
			cout << endl;
		}
		cout << "Press any key to continue : ";
		char s = _getch();
	}
	void AddCarriage()
	{
		Carriage* temp = new Carriage[carriageCount + 1];
		for (int i = 0; i < carriageCount; i++)
		{
			temp[i] = carriages[i];
		}
		system("cls");
		int placeCount, passangerCount;
		bool isValidData = false;
		while (!isValidData)
		{
			try
			{
				cout << "Enter place count : "; cin >> placeCount;
				if (placeCount < 0) throw exception("place count < 0");
				cout << "Enter passanger count : "; cin >> passangerCount;
				if (passangerCount > placeCount) throw exception("passanger count > place count");
				if (passangerCount < 0) throw exception("passanger count < 0");
				isValidData = true;
			}
			catch (exception ex)
			{
				system("cls");
				cout << "Error! " << ex.what() << endl;
				cout << endl;
			}
		}
		temp[carriageCount] = Carriage(carriageCount + 1, placeCount, passangerCount);
		carriageCount++;
		if (carriages != nullptr)
			delete[] carriages;
		carriages = temp;
		cout << endl;
		cout << "Carriage added" << endl;
		cout << endl;
		cout << "Press any key to continue : ";
		char s = _getch();
	}
	void DeleteCarriageByNumber()
	{
		system("cls");
		if (carriages != nullptr)
		{
			int number;
			bool isValidData = false;
			while (!isValidData)
			{
				try
				{
					cout << endl;
					cout << "======== Train : " << model << " ========" << endl;
					for (int i = 0; i < carriageCount; i++)
					{
						carriages[i].Show();
					}
					cout << "Enter carriage number ";
					if (carriageCount == 1) cout << "(1) : ";
					else cout << "(1 - " << carriageCount << ") : ";
					cin >> number;
					if (number < 1) throw exception("number < 1");
					if (number > carriageCount) throw exception("number > carriage count");
					isValidData = true;
				}
				catch (exception ex)
				{
					system("cls");
					cout << "Error! " << ex.what() << endl;
					cout << endl;
				}
			}
			Carriage* temp = new Carriage[--carriageCount];
			for (int i = 0; i < number - 1; i++)
			{
				temp[i] = carriages[i];
			}
			for (int i = number; i < carriageCount; i++)
			{
				temp[i] = carriages[i + 1];
				temp[i].DecreaseNumber();
			}
			if (carriages != nullptr)
				delete[] carriages;
			carriages = temp;
			cout << endl;
			cout << "Carriage deleted" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
		else
		{
			cout << "Carriages not found" << endl;
			cout << endl;
			cout << "Press any key to continue : ";
			char s = _getch();
		}
	}
	void Save()
	{
		ofstream out("Train.txt", ios_base::out);
		out << model << endl;
		out << carriageCount << endl;
		for (int i = 0; i < carriageCount; i++)
		{
			out << carriages[i];
		}
		out.close();
	}
	void Load()
	{
		ifstream in("Train.txt", ios_base::in);
		getline(in, model);
		in >> carriageCount;
		if (carriages != nullptr)
			delete[] carriages;
		carriages = new Carriage[carriageCount];
		for (int i = 0; i < carriageCount; i++)
		{
			in >> carriages[i];
		}
		in.close();
	}

	~Train()
	{
		if (carriages != nullptr)
			delete[] carriages;
	}
};



int main()
{
	Train train1("Tom");
	/*train1.Show();
	train1.AddCarriage();
	train1.AddCarriage();
	train1.AddCarriage();
	train1.AddCarriage();

	train1.Save();
	train1.DeleteCarriageByNumber();
	train1.DeleteCarriageByNumber();
	train1.DeleteCarriageByNumber();
	train1.DeleteCarriageByNumber();*/
	train1.Load();
	train1.Show();
}