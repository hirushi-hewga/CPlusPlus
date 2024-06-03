#include <iostream>
using namespace std;

class Array
{
	int size;
	long* arr;
public:
	Array() :size(0), arr(nullptr) {}
	Array(int size) :size(size)
	{
		arr = nullptr;
		if (size != 0) {
			arr = new long[size];
			for (int i = 0; i < size; i++)
			{
				*(arr + i) = 0;
			}
		}
	}
	Array(const Array& other) :size(other.size)
	{
		arr = new long[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}



	void Show()const
	{
		cout << "======== Array ========" << endl;
		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << ' ';
			}
		}
		else cout << "      :EMPTY_ARRAY:" << endl;
		cout << endl;
	}
	void FillRandom()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 101 - 50;
		}
		if (size == 0) cout << "Error. Empty array!" << endl;
	}
	void FillFromKeyboard()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Enter element : ";
			cin >> arr[i];
		}
		if (size == 0) cout << "Error. Empty array!" << endl;
	}
	void FillDefault()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
		if (size == 0) cout << "Error. Empty array!" << endl;
	}
	void AddElement()
	{
		long* temp = new long[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		if (arr != nullptr)
			delete[] arr;
		temp[size] = 0;
		arr = temp;
		size++;
	}
	void DeleteElementByIndex()
	{
		if (size >= 1) {
			Show();
			int index = -1;
			bool isValidData = true;
			while (index < 0 || index > size - 1) {
				if (!isValidData) cout << "Error index. Try again!" << endl;
				isValidData = false;
				cout << "Enter element index to delete : ";
				cin >> index;
			}
			long* temp = new long[size - 1];
			for (int i = 0; i < index; i++)
			{
				temp[i] = arr[i];
			}
			for (int i = index + 1; i < size; i++)
			{
				temp[i - 1] = arr[i];
			}
			if (arr != nullptr)
				delete[] arr;
			arr = temp;
			size--;
		}
		else cout << "Error. Empty array!" << endl;
	}
	void SortArray1(long* arr, int low, int high)
	{
		if (low < high) {
			long pivot = arr[high];
			int i = low - 1;

			for (int j = low; j <= high - 1; j++) {
				if (arr[j] < pivot) {
					i++;
					long temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
			long temp = arr[i + 1];
			arr[i + 1] = arr[high];
			arr[high] = temp;

			int value = i + 1;

			SortArray1(arr, low, value - 1);
			SortArray1(arr, value + 1, high);
		}
	}
	void SortArray2(long* arr, int low, int high)
	{
		if (low < high) {
			long pivot = arr[high];
			int i = low - 1;

			for (int j = low; j <= high - 1; j++) {
				if (arr[j] > pivot) {
					i++;
					long temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
			long temp = arr[i + 1];
			arr[i + 1] = arr[high];
			arr[high] = temp;

			int pi = i + 1;

			SortArray2(arr, low, pi - 1);
			SortArray2(arr, pi + 1, high);
		}
	}
	void QuickSort()
	{
		if (size != 0)
		{
			int choice = 0;
			bool isValidData = true;
			while (choice < 1 || choice > 2)
			{
				if (!isValidData) cout << "Error choice. Try again!" << endl;
				isValidData = false;
				cout << "1 - Sort by growth" << endl;
				cout << "2 - Sort by decline" << endl;
				cout << "Enter your choice : ";
				cin >> choice;
			}
			if (choice == 1) SortArray1(arr, 0, size - 1);
			if (choice == 2) SortArray2(arr, 0, size - 1);
		}
		else cout << "Error. Empty array!" << endl;
	}
	void GetValue()
	{
		long min = *arr;
		long max = *arr;
		long average = 0;
		for (int i = 0; i < size; i++)
		{
			if (*(arr + i) < min) min = *(arr + i);
			if (*(arr + i) > max) max = *(arr + i);
			average += *(arr + i);
		}
		average /= size;
		Show();
		cout << "Min value : " << min << endl;
		cout << "Max value : " << max << endl;
		cout << "Average number : " << average << endl;
	}



	~Array()
	{
		delete[] arr;
	}
};



enum FILL { RANDOM = 1, KEYBOARD, DEFAULT };
void Init(Array& arr)
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 3)
	{
		if (!isValidData) cout << "Error choice. Try again!" << endl;
		isValidData = false;
		cout << "1 - Fill random" << endl;
		cout << "2 - Fill from keyboard" << endl;
		cout << "3 - Init default (0)" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	switch (choice)
	{
	case FILL::RANDOM: arr.FillRandom(); break;
	case FILL::KEYBOARD: arr.FillFromKeyboard(); break;
	case FILL::DEFAULT: arr.FillDefault();
	}
}




int Menu()
{
	int choice = 0;
	bool isValidData = true;
	while (choice < 1 || choice > 7)
	{
		if (!isValidData) cout << "Error data. Try again!" << endl;
		isValidData = false;
		cout << endl;
		cout << "1 - Init array" << endl;
		cout << "2 - Show all array" << endl;
		cout << "3 - Add element to array" << endl;
		cout << "4 - Remove array element" << endl;
		cout << "5 - Sort array" << endl;
		cout << "6 - Get min max element, average value from array" << endl;
		cout << "7 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
	}
	return choice;
}
enum MENU { INIT = 1, SHOW, ADD_ELEM, RM_ELEM, SORT, GET_VALUES, EXIT };
int main()
{
	srand(time(NULL));
	Array arr;
	bool isExit = false;
	while (!isExit)
	{
		cout << "========================" << endl;
		switch (Menu())
		{
		case MENU::INIT: Init(arr); break;
		case MENU::SHOW: arr.Show(); break;
		case MENU::ADD_ELEM: arr.AddElement(); break;
		case MENU::RM_ELEM: arr.DeleteElementByIndex(); break;
		case MENU::SORT: arr.QuickSort(); break;
		case MENU::GET_VALUES: arr.GetValue(); break;
		case MENU::EXIT: isExit = true;
		}
	}
	cout << "Good bye." << endl;
}