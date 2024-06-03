#include <iostream>
using namespace std;

struct Carriage
{
private:
	int number;
	int places;
	int passangers;
public:
	void Show()
	{
		cout << "======== Carriage [" << number << "] ========" << endl;
		cout << "Places : " << places << endl;
		cout << "Passangers : " << passangers << endl;
	}
	void InitCarriage(int countCarriages)
	{
		number = countCarriages + 1;
		places = 20;
		passangers = 0;
	}
	void SetNumber(int number)
	{
		this->number = number;
	}
	void SetPlaces(int places)
	{
		this->places = places;
	}
	void SetPassangers(int passangers)
	{
		this->passangers = passangers;
	}
	int GetNumber()
	{
		return number;
	}
	int GetPlaces()
	{
		return places;
	}
	int GetPassangers()
	{
		return passangers;
	}
};




class Train
{
	string model;
	int countCarriages;
	Carriage* carriages;
public:
	Train()
	{
		cout << "-- Construct --" << endl;
		model = "No model";
		countCarriages = 0;
		carriages = nullptr;
	}
	Train(string model)
	{
		cout << "-- Construct --" << endl;
		this->model = model;
		countCarriages = 0;
		carriages = nullptr;
	}
	Train(const Train& other)
	{
		model = other.model;
		countCarriages = other.countCarriages;
		carriages = nullptr;
		if (countCarriages != 0)
		{
			Carriage* temp = new Carriage[countCarriages];
			for (int i = 0; i < countCarriages; i++)
			{
				temp[i] = other.carriages[i];
			}
			carriages = temp;
		}
	}




	void Show()
	{
		cout << endl;
		cout << "Train : " << model << endl;
		for (int i = 0; i < countCarriages; i++)
		{
			carriages[i].Show();
			cout << endl;
		}
	}
	void AddCarriage()
	{
		Carriage* temp = new Carriage[countCarriages + 1];
		for (int i = 0; i < countCarriages; i++)
		{
			temp[i] = carriages[i];
		}
		temp[countCarriages].InitCarriage(countCarriages);
		if (carriages != nullptr)
			delete[] carriages;
		carriages = temp;
		countCarriages++;
	}
	string GetModel()
	{
		return model;
	}
	void AddPassanger()
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > countCarriages)
		{
			if (!isValidData) cout << "Error data. Try again!" << endl;
			isValidData = false;
			cout << "Enter carriage ( 1 - " << countCarriages << " ) to add passanger : ";
			cin >> choice;
		}
		if (carriages[choice - 1].GetPlaces() <= carriages[choice - 1].GetPassangers()) cout << "Error data. Carriage is full" << endl;
		else carriages[choice - 1].SetPassangers(carriages[choice - 1].GetPassangers() + 1); cout << "Passanger added" << endl;
	}




	~Train()
	{
		cout << "-- Destruct " << model << " --" << endl;
		delete[] carriages;
	}
};




struct Depot
{
	int countTrains;
	Train* trains;
public:
	Depot()
	{
		countTrains = 0;
		trains = nullptr;
	}




	void Show()
	{
		if (trains != nullptr) for (int i = 0; i < countTrains; i++) trains[i].Show();
		else cout << "Not found trains!" << endl;
	}
	void AddTrain()
	{
		int choice = 0;
		bool isValidData = true;
		while (choice < 1 || choice > 2)
		{
			if (!isValidData) cout << "Error data. Try again!" << endl;
			isValidData = false;
			cout << "1 - Add default train" << endl;
			cout << "2 - Add train by name" << endl;
			cout << "Enter your choice : ";
			cin >> choice;
		}
		cout << endl;
		Train* temp = new Train[countTrains + 1];
		for (int i = 0; i < countTrains; i++)
		{
			temp[i] = Train(trains[i]);
		}
		if (choice == 2)
		{
			string name;
			cout << endl;
			cout << "Enter name : ";
			cin >> name;
			temp[countTrains] = Train(name);
		}
		if (trains != nullptr)
			delete[] trains;
		trains = temp;
		countTrains++;
	}
	void AddCarriage()
	{
		if (trains != nullptr)
		{
			int choice = 0;
			bool isValidData = true;
			while (choice < 1 || choice > countTrains)
			{
				if (!isValidData) cout << "Error data. Try again!" << endl;
				isValidData = false;
				for (int i = 0; i < countTrains; i++)
				{
					cout << i + 1 << " - Train " << trains[i].GetModel() << endl;
				}
				cout << "Choice train [ 1 - " << countTrains << " ] to add carriage : ";
				cin >> choice;
			}
			trains[choice - 1].AddCarriage();
		}
		else cout << "Not found trains!" << endl;
	}
	void AddPassanger()
	{
		if (trains != nullptr)
		{
			int choice = 0;
			bool isValidData = true;
			while (choice < 1 || choice > countTrains)
			{
				if (!isValidData) cout << "Error data. Try again!" << endl;
				isValidData = false;
				for (int i = 0; i < countTrains; i++)
				{
					cout << i + 1 << " - Train " << trains[i].GetModel() << endl;
				}
				cout << "Choice train [ 1 - " << countTrains << " ] to add passanger : ";
				cin >> choice;
			}
			trains[choice - 1].AddPassanger();
		}
		else cout << "Not found trains!" << endl;
	}
	void CopyTrain()
	{
		if (trains == nullptr) cout << "Not found trains" << endl;
		else {
			int choice = 0;
			bool isValidData = true;
			while (choice < 1 || choice > countTrains)
			{
				if (!isValidData) cout << "Error data. Try again!" << endl;
				isValidData = false;
				cout << "Choice train ( 1 - " << countTrains << " ) to copy : ";
				cin >> choice;
			}
			cout << endl;
			Train* temp = new Train[countTrains + 1];
			for (int i = 0; i < countTrains; i++)
			{
				temp[i] = Train(trains[i]);
			}
			temp[countTrains] = Train(trains[choice - 1]);
			delete[] trains;
			trains = temp;
			countTrains++;
		}
	}




	~Depot()
	{
		delete[] trains;
	}
};






int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 6)
	{
		if (!isValidData) cout << "Error data. Try again!" << endl;
		isValidData = false;
		cout << "1 - Show train" << endl;
		cout << "2 - Add train" << endl;
		cout << "3 - Copy train" << endl;
		cout << "4 - Add carriage" << endl;
		cout << "5 - Add passanger" << endl;
		cout << "6 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { SHOW = 1, ADD_TRAIN, COPY_TRAIN, ADD_CARRIAGE, ADD_PASSANGER, EXIT };
int main()
{
	Depot depot;
	bool isExit = false;
	while (!isExit)
	{
		cout << endl;
		cout << "------------------------" << endl;
		switch (Menu())
		{
		case MENU::SHOW: depot.Show(); break;
		case MENU::ADD_TRAIN: depot.AddTrain(); break;
		case MENU::COPY_TRAIN: depot.CopyTrain(); break;
		case MENU::ADD_CARRIAGE: depot.AddCarriage(); break;
		case MENU::ADD_PASSANGER: depot.AddPassanger(); break;
		case MENU::EXIT: isExit = true;
		}
		cout << "------------------------" << endl;
	}
	cout << "Good bye." << endl;
}