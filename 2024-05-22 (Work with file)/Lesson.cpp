#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
using namespace std;

class Animal
{
	string name;
	float weight;
	string place;
public:
	Animal() :name("no name"), weight(0), place("no place") {}
	Animal(string name, float weight, string place) :name(name), weight(weight), place(place)
	{
		this->weight = weight > 0 ? weight : 0;
	}
	void ShowInfo()const
	{
		cout << "Name : " << name << endl;
		cout << "Weight : " << weight << " kg" << endl;
		cout << "Place : " << place << endl;
	}
	friend ofstream& operator <<(ofstream& of, const Animal& animal);
	friend ifstream& operator >>(ifstream& in, Animal& animal);
};
ofstream& operator <<(ofstream& of, const Animal& animal)
{
	of << animal.name << ' ' << animal.weight << ' ' << animal.place;
	return of;
}
ifstream& operator >>(ifstream& in, Animal& animal)
{
	in >> animal.name >> animal.weight >> animal.place;
	return in;
}

class Zoo
{
	string name;
	Animal* animals;
	int animalCount;
public:
	Zoo() = delete;
	Zoo(string name) : name(name), animals(nullptr), animalCount(0) {}
	void AddAnimal(Animal animal)
	{
		Animal* temp = new Animal[animalCount + 1];
		for (int i = 0; i < animalCount; i++)
		{
			temp[i] = animals[i];
		}
		temp[animalCount++] = animal;
		if (animals != nullptr)
			delete[] animals;
		animals = temp;
	}
	void Show()const
	{
		cout << "________ Zoo : " << name << " ________" << endl;
		cout << "Name : " << name << endl;
		for (int i = 0; i < animalCount; i++)
		{
			animals[i].ShowInfo();
			cout << endl;
		}
	}
	void Save()const
	{
		ofstream out("Zoo.txt", ios_base::out);
		out << name << endl;
		out << animalCount << endl;
		for (int i = 0; i < animalCount; i++)
		{
			out << animals[i];
		}
		out.close();
		cout << "Save to file" << endl;
	}
	void Load()
	{
		ifstream in("Zoo.txt", ios_base::in);
		// char buff[255];
		// in.getline(buff, 255);
		// name = buff;
		/*in >> name;*/
		getline(in, name);
		in >> animalCount;
		if (animals != nullptr)
			delete[] animals;
		animals = new Animal[animalCount];
		for (int i = 0; i < animalCount; i++)
		{
			in >> animals[i];
		}
		in.close();
	}
	void SaveBinary()
	{
		ofstream out("Zoo.bin", ios_base::out | ios_base::binary);
		out.write((char*)&name, sizeof(name));
		out.write((char*)&animalCount, sizeof(animalCount));
		for (int i = 0; i < animalCount; i++)
		{
			out.write((char*)&animals[i], sizeof(animals[i]));
		}
		out.close();
	}void BinaryLoad()
	{
		ifstream in("Zoo.bin", ios_base::in | ios_base::binary);
		in.read((char*)&name, sizeof(name));
		in.read((char*)&animalCount, sizeof(animalCount));
		if (animals != nullptr)
			delete[] animals;
		animals = new Animal[animalCount];
		for (int i = 0; i < animalCount; i++)
		{
			in.read((char*)&animals[i], sizeof(animals[i]));
		}
		in.close();
	}

	~Zoo()
	{
		if (animals != nullptr)
			delete[] animals;
	}
};



//int main()
//{
	/*Animal animal("Tom", 10, "Flat");
	animal.ShowInfo();
	Zoo zoo("Romashka");
	zoo.AddAnimal(animal);
	zoo.AddAnimal(Animal("Lion", 150, "Africa"));
	zoo.AddAnimal(Animal("Elephant", 1500, "Africa"));
	zoo.AddAnimal(Animal("Pig", 200, "Village"));
	zoo.Show();
	zoo.SaveBinary();

	Zoo zoo("test");
	zoo.Show();
	zoo.BinaryLoad();
	zoo.Show();*/
	//}