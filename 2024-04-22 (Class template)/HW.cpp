#include <iostream>
using namespace std;

template<typename T_value>
class Array
{
	int size;
	T_value* arr;
public:
	Array() :size(0), arr(nullptr) {}
	Array(int size) :size(size)
	{
		arr = nullptr;
		if (size != 0) {
			arr = new T_value[size];
			for (int i = 0; i < size; i++)
			{
				*(arr + i) = 0;
			}
		}
	}
	Array(const initializer_list<int>& list)
	{
		this->size = list.size();
		arr = new T_value[size];
		int i = 0;
		for (T_value elem : list)
		{
			arr[i++] = elem;
		}
	}
	Array(const Array& other) :size(other.size)
	{
		arr = new T_value[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}



	void Show()const
	{
		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << ' ';
			}
		}
		else cout << "    :EMPTY_ARRAY:" << endl;
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
		T_value* temp = new T_value[size + 1];
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
			T_value* temp = new T_value[size - 1];
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
	void SortArray1(int low, int high)
	{
		if (low < high) {
			T_value pivot = arr[high];
			int i = low - 1;

			for (int j = low; j <= high - 1; j++) {
				if (arr[j] < pivot) {
					i++;
					T_value temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
			T_value temp = arr[i + 1];
			arr[i + 1] = arr[high];
			arr[high] = temp;

			int value = i + 1;

			SortArray1(low, value - 1);
			SortArray1(value + 1, high);
		}
	}
	void SortArray2(int low, int high)
	{
		if (low < high) {
			T_value pivot = arr[high];
			int i = low - 1;

			for (int j = low; j <= high - 1; j++) {
				if (arr[j] > pivot) {
					i++;
					T_value temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
			T_value temp = arr[i + 1];
			arr[i + 1] = arr[high];
			arr[high] = temp;

			int pi = i + 1;

			SortArray2(low, pi - 1);
			SortArray2(pi + 1, high);
		}
	}

	void QuickSort();
	void GetValue();
	void FillFromList(const initializer_list<int>& list);
	int BinarySearch(T_value key);
	void ChangeElemByIndex(T_value newElem, int index);



	~Array()
	{
		delete[] arr;
	}
};



template<typename T_value>
void Array<T_value>::ChangeElemByIndex(T_value newElem, int index)
{
	if (index < size && index > 0) arr[index] = newElem;
}
template<typename T_value>
int Array<T_value>::BinarySearch(T_value key)
{
	int b = 0, e = size - 1;
	while (true)
	{
		int p = (b + e) / 2;
		if (key > arr[p])
		{
			b = p + 1;
		}
		else if (key < arr[p])
		{
			e = p - 1;
		}
		else if (key == arr[p])
		{
			return p;
		}

		if (b > e) return -1;
	}
}
template<typename T_value>
void Array<T_value>::FillFromList(const initializer_list<int>& list)
{
	this->size = list.size();
	if (arr != nullptr)
		delete[] arr;
	arr = new T_value[size];
	int i = 0;
	for (T_value num : list)
	{
		arr[i++] = num;
	}
}
template<typename T_value>
void Array<T_value>::GetValue()
{
	T_value min = *arr;
	T_value max = *arr;
	float average = 0;
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
template<typename T_value>
void Array<T_value>::QuickSort()
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
		if (choice == 1) SortArray1(0, size - 1);
		if (choice == 2) SortArray2(0, size - 1);
	}
	else cout << "Error. Empty array!" << endl;
}



int main()
{
	Array<int> arr1({ 12, 45, 23, 34, 56, 15, 74 });
	Array<int> arr2({ 56, 89, 67, 78 });
	cout << "==== Array 1 ====" << endl; arr1.Show();
	cout << "==== Array 2 ====" << endl; arr2.Show();
	cout << endl;
	arr1.FillFromList({ 1, 4, 2, 3 });
	arr2.FillFromList({ 5, 8, 6, 7, 9, 3, 4 });
	cout << "==== Array 1 ====" << endl; arr1.Show();
	cout << "==== Array 2 ====" << endl; arr2.Show();
	cout << endl;
	arr1.QuickSort();
	arr2.QuickSort();
	cout << "==== Array 1 ====" << endl; arr1.Show();
	cout << "==== Array 2 ====" << endl; arr2.Show();
	cout << endl;
	arr1.GetValue();
	cout << endl;
	arr2.GetValue();
	cout << endl;
	int resArr1 = arr1.BinarySearch(3);
	int resArr2 = arr2.BinarySearch(8);
	cout << "index 1 : " << resArr1 << endl;
	cout << "index 2 : " << resArr2 << endl;
}