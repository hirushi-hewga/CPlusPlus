#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cctype>
using namespace std;

struct WashMashine
{
	char company[20];
	char color[20];
	float width;
	float length;
	float height;
	float power;
	float spinSpeed;
	float heatingTemperature;
};

struct Praska
{
	char brand[20];
	char model[20];
	char color[20];
	int minTemperature;
	int maxTemperature;
	char steamDelivery;
	int power;
};

struct Boiler
{
	char company[20];
	char color[20];
	int power;
	int capacity;
	int heatingTemperature;
};

struct CarNumber
{
	char a[3];
	int b;
	char c[3];
};

struct MotorCar
{
	int id;
	char color[20];
	char model[20];
	CarNumber number;
};



WashMashine CreateWashMashine()
{
	WashMashine temp;
	cout << "Enter washing mashine company: ";
	cin >> temp.company;
	cout << "Enter washing mashine color: ";
	cin >> temp.color;
	cout << "Enter washing mashine width: ";
	cin >> temp.width;
	cout << "Enter washing mashine length: ";
	cin >> temp.length;
	cout << "Enter washing mashine height: ";
	cin >> temp.height;
	cout << "Enter washing mashine power: ";
	cin >> temp.power;
	cout << "Enter washing mashine spin speed: ";
	cin >> temp.spinSpeed;
	cout << "Enter washing mashine heating temperature: ";
	cin >> temp.heatingTemperature;
	return temp;
}

Praska CreatePraska()
{
	Praska temp;
	cout << "Enter praska brand: ";
	cin >> temp.brand;
	cout << "Enter praska model: ";
	cin >> temp.model;
	cout << "Enter praska color: ";
	cin >> temp.color;
	cout << "Enter praska minimum temperature: ";
	cin >> temp.minTemperature;
	cout << "Enter praska maximum temperature: ";
	cin >> temp.maxTemperature;
	cout << "Enter praska steam delivery y/n: ";
	temp.steamDelivery = _getch();
	cout << endl;
	cout << "Enter praska power: ";
	cin >> temp.power;
	return temp;
}

Boiler CreateBoiler()
{
	Boiler temp;
	cout << "Enter boiler company: ";
	cin >> temp.company;
	cout << "Enter boiler color: ";
	cin >> temp.color;
	cout << "Enter boiler power: ";
	cin >> temp.power;
	cout << "Enter boiler capacity: ";
	cin >> temp.capacity;
	cout << "Enter boiler heating temperature: ";
	cin >> temp.heatingTemperature;
	return temp;
}



void ShowWashMashine(WashMashine m)
{
	cout << "============== WashingMashine ==============" << endl;
	cout << "Company: " << m.company << endl;
	cout << "Color: " << m.color << endl;
	cout << "Width: " << m.width << endl;
	cout << "Length: " << m.length << endl;
	cout << "Height: " << m.height << endl;
	cout << "Power: " << m.power << endl;
	cout << "Spin speed: " << m.spinSpeed << endl;
	cout << "Heating temperature: " << m.heatingTemperature << endl;
}

void ShowPraska(Praska p)
{
	cout << "================== Praska ==================" << endl;
	cout << "Brand: " << p.brand << endl;
	cout << "Model: " << p.model << endl;
	cout << "Color: " << p.color << endl;
	cout << "Minimum temperature: " << p.minTemperature << endl;
	cout << "Maximum temperature: " << p.maxTemperature << endl;
	cout << "Steam delivery y/n: " << p.steamDelivery << endl;
	cout << "Power: " << p.power << endl;
}

void ShowBoiler(Boiler b)
{
	cout << "================== Boiler ==================" << endl;
	cout << "Company: " << b.company << endl;
	cout << "Color: " << b.color << endl;
	cout << "Power: " << b.power << endl;
	cout << "Capacity: " << b.capacity << endl;
	cout << "Heating temperature: " << b.heatingTemperature << endl;
}

MotorCar* CopyStructures(MotorCar* c, int& size);
void ShowAllCars(MotorCar* cars, int size);
void ShowCarById(MotorCar* c, int size);
void ShowCarsId(MotorCar* c, int size);
void SearchCarByNumber(MotorCar* c, int size);
void ShowCarsNumber(MotorCar* c, int size);
MotorCar* EditCar(MotorCar* c, int size);
MotorCar* InitCar(MotorCar* c, MotorCar car, int index, int size);
MotorCar* AddNewCar(MotorCar* c, int& size);

int main()
{
	/*
	WashMashine washingMashine = CreateWashMashine();
	ShowWashMashine(washingMashine);
	*/




	/*
	Praska praska = CreatePraska();
	ShowPraska(praska);
	*/




	/*
	Boiler boiler = CreateBoiler();
	ShowBoiler(boiler);
	*/




	/*
	int size = 10;
	MotorCar* cars = new MotorCar[size];
	cars = CopyStructures(cars, size);

	bool BOOL = false;
	int choice;
	do
	{
		cout << endl;
		if (BOOL) cout << "Error choice. Try again!" << endl;
		BOOL = false;
		cout << "1 - show all cars" << endl;
		cout << "2 - show car by id" << endl;
		cout << "3 - show car by number" << endl;
		cout << "4 - edit car by number" << endl;
		cout << "5 - add new car" << endl;
		cout << "0 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		cout << endl;
		if (choice < 0 || choice > 5)
		{
			BOOL = true;
			continue;
		}
		switch (choice)
		{
		case 1: ShowAllCars(cars, size); break;
		case 2: ShowCarById(cars, size); break;
		case 3: SearchCarByNumber(cars, size); break;
		case 4: cars = EditCar(cars, size); break;
		case 5: cars = AddNewCar(cars, size); break;
		default: BOOL = true;
		}
		cout << endl;
	} while (choice != 0);
	cout << "Good bye!" << endl;

	delete[] cars;
	*/
}



MotorCar* AddNewCar(MotorCar* c, int& size)
{
	size++;
	MotorCar* temp = new MotorCar[size]{};
	for (int i = 0; i < size - 1; i++)
	{
		*(temp + i) = *(c + i);
	}
	delete[] c;
	c = InitCar(temp, *(temp + size - 1), size - 1, size);
	return c;
}

MotorCar* InitCar(MotorCar* c, MotorCar car, int index, int size)
{
	bool BOOL = false;
	int* id = new int[size - 1];
	for (int i = 0; i < index; i++) *(id + i) = (*(c + i)).id;
	for (int i = index + 1; i < size; i++) *(id + i - 1) = (*(c + i)).id;
	do
	{
		if (BOOL)
		{
			cout << "Id exist. Try again!" << endl;
		}
		BOOL = false;
		cout << "Enter id : ";
		cin >> car.id;
		for (int i = 0; i < size - 1; i++)
		{
			if (car.id == *(id + i))
			{
				BOOL = true;
				break;
			}
		}
	} while (BOOL);
	delete[] id;

	cout << "Enter car color : ";
	cin >> car.color;

	cout << "Enter car model : ";
	cin >> car.model;

	BOOL = false;
	string region;
	do {
		if (BOOL)
		{
			cout << "Error region. Try again!" << endl;
		}
		BOOL = false;
		cout << "Enter car region (BK) : ";
		cin >> region;
		if (!(isupper(region[0]) && isalpha(region[0]) && isupper(region[1]) && isalpha(region[1])))
		{
			BOOL = true;
		}
	} while (BOOL);
	car.number.a[0] = region[0];
	car.number.a[1] = region[1];

	BOOL = false;
	int number;
	do {
		if (BOOL)
		{
			cout << "Error number. Try again!" << endl;
		}
		BOOL = false;
		cout << "Enter car number (1234) : ";
		cin >> number;
		if (!(number / 1000 < 10 && number / 1000 > 0))
		{
			BOOL = true;
		}
	} while (BOOL);
	car.number.b = number;

	BOOL = false;
	string series;
	do {
		if (BOOL)
		{
			cout << "Error series. Try again!" << endl;
		}
		BOOL = false;
		cout << "Enter car series (IT) : ";
		cin >> series;
		if (!(isupper(series[0]) && isalpha(series[0]) && isupper(series[1]) && isalpha(series[1])))
		{
			BOOL = true;
		}
	} while (BOOL);
	car.number.c[0] = series[0];
	car.number.c[1] = series[1];

	*(c + index) = car;
	return c;
}

MotorCar* EditCar(MotorCar* c, int size)
{
	ShowCarsNumber(c, size);
	int Index;
	cout << "Choice car number (1 - " << size << ") : ";
	cin >> Index;
	while (Index<1 || Index>size)
	{
		cout << "Try again : ";
		cin >> Index;
	}
	Index--;
	//for (int i = 0; i < Index; i++)
	//{
	//	*(temp + i) = *(c + i);
	//}
	c = InitCar(c, *(c + Index), Index, size);
	//for (int i = Index + 1; i < size; i++)
	//{
	//	*(temp + i) = *(c + i);
	//}
	return c;
}

void ShowCarsNumber(MotorCar* c, int size)
{
	cout << "======= Number =======" << endl;
	for (int i = 0; i < size; i++) cout << i + 1 << " - " << c[i].number.a << c[i].number.b << c[i].number.c << endl;
}

void SearchCarByNumber(MotorCar* c, int size)
{
	ShowCarsNumber(c, size);
	int choice;
	cout << "Choice car number (1 - " << size << ") : ";
	cin >> choice;
	while (choice<1 || choice>size)
	{
		cout << "Try again : ";
		cin >> choice;
	}
	cout << "----------------------" << endl;
	cout << "Id : " << c[choice - 1].id << endl;
	cout << "Color : " << c[choice - 1].color << endl;
	cout << "Model : " << c[choice - 1].model << endl;
	cout << "Number : " << c[choice - 1].number.a << c[choice - 1].number.b << c[choice - 1].number.c << endl;
	cout << "----------------------" << endl;
}

void ShowCarsId(MotorCar* c, int size)
{
	cout << "========= Id =========" << endl;
	for (int i = 0; i < size; i++) cout << "Id : " << c[i].id << ", Model : " << c[i].model << endl;
}

void ShowCarById(MotorCar* c, int size)
{
	bool BOOL = false;
	ShowCarsId(c, size);
	int choice;
	cout << "Enter id : ";
	cin >> choice;
	int* id = new int[size];
	for (int i = 0; i < size; i++) *(id + i) = (*(c + i)).id;
	int carIndex;
	do
	{
		if (BOOL)
		{
			cout << "Try again : ";
			cin >> choice;
		}
		BOOL = true;
		for (int i = 0; i < size; i++) if (choice == c[i].id)
		{
			BOOL = false;
			carIndex = i;
			break;
		}
	} while (BOOL);
	delete[] id;
	cout << "----------------------" << endl;
	cout << "Id : " << c[carIndex].id << endl;
	cout << "Color : " << c[carIndex].color << endl;
	cout << "Model : " << c[carIndex].model << endl;
	cout << "Number : " << c[carIndex].number.a << c[carIndex].number.b << c[carIndex].number.c << endl;
	cout << "----------------------" << endl;
}

void ShowAllCars(MotorCar* c, int size)
{
	cout << "======== Cars ========" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Id : " << c[i].id << endl;
		cout << "Color : " << c[i].color << endl;
		cout << "Model : " << c[i].model << endl;
		cout << "Number : " << c[i].number.a << c[i].number.b << c[i].number.c << endl;
		cout << "----------------------" << endl;
	}
}

MotorCar* CopyStructures(MotorCar* c, int& size)
{
	MotorCar* temp = new MotorCar[size]{
		{ 1, "orange","Skoda",{"BK",1111,"IT"} },
		{ 2, "green","Mazda",{"BK",1112,"IT"} },
		{ 3, "blue","Toyota",{"BK",1113,"IT"} },
		{ 4, "red","Honda",{"BK",1114,"IT"} },
		{ 5, "yellow","Ford",{"BK",1115,"IT"} },
		{ 6, "black","Chevrolet",{"BK",1116,"IT"} },
		{ 7, "white","Nissan",{"BK",1117,"IT"} },
		{ 8, "silver","Hyundai",{"BK",1118,"IT"} },
		{ 9, "gray","Kia",{"BK",1119,"IT"} },
		{ 10, "purple","Volkswagen",{"BK",1120,"IT"}
	} };
	return temp;
}