#include <iostream>
using namespace std;

//add element
int Push_front(int* arr, int element, int size, bool Empty) {
	for (int i = 0; i < size; i++) 
	{
		if (arr[i] == 0) 
		{
			arr[i] = element;
			break;
		}
	}
	Empty = false;
	return Empty;
}
//Delete element
int Delete(int* arr, int size, bool FULL) {
	arr[0] = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == arr[size - 1]) 
		{
			break;
		}
		if (arr[i] == 0) 
		{
			arr[i] = arr[i + 1];
			arr[i + 1] = 0;
		}
	}
	FULL = false;
	return FULL;
}
//Show Queue
void Show_Stack(int* arr, int size, bool Empty)
{
	if (Empty == true) {
		cout << "Queue is fully empty, add something" << endl;
	}
	else 
	{
		for (int i = 0; i < size; i++)
			if (arr[i] != 0)
				cout << arr[i] << " ";
		cout << endl;
	}
}
//Empty check
int EMPTY(int* arr, bool Empty)
{
	if (arr[0] == 0)
		Empty = true;
	return Empty;
}
//Empty Full
int Full(int* arr, int size, bool FULL)
{
	if (arr[size - 1] != 0) {
		FULL = true;
	}
	return FULL;
}
int main() {
	bool FULL = false, Empty = true;
	int element, opperation;
	int const size = 10;
	int* arr = new int[size];
	for (int j = 0; j < size; j++)
		arr[j] = 0;
	cout << "Tip: Queue limit is ten elements" << endl;
	while (true) {
		cout << "1.Add Element" << endl;
		cout << "2.Show Queue" << endl;
		cout << "3.Delete Element" << endl;
		cin >> opperation;
		if (opperation == 1) {
			if (Full(arr, size, FULL) == false)
			{
				cout << "Enter element: ";
				cin >> element;
				Empty = Push_front(arr, element, size, Empty);
			}
			else 
			{
				cout << "Queue is full" << endl;
				cout << endl;
			}
			cout << "Do you wish to continie? 1=continie 2=exit:";
			cin >> opperation;
			if (opperation == 1) 
			{
				continue;
			}
			if (opperation == 2)
			{
				break;
			}
			else
			{
				cout << "Enter existed operation" << endl;
			}
		}
		if (opperation == 2) 
		{
			Show_Stack(arr, size, Empty);
			cout << "Do you wish to continie? 1=continie 2=exit:";
			cin >> opperation;
			if (opperation == 1) 
			{
				continue;
			}
			if (opperation == 2) 
			{
				break;
			}
			else {
				cout << "Enter existed operation" << endl;
			}

		}
		if (opperation == 3) 
		{
			if (EMPTY(arr, Empty) == false)
				FULL = Delete(arr, size, FULL);
			else 
			{
				cout << "Queue is empty" << endl;
				cout << endl;
			}
			cout << "Do you wish to continie? 1=continie 2=exit:";
			cin >> opperation;
			if (opperation == 1) 
			{
				continue;
			}
			if (opperation == 2) 
			{
				break;
			}
			else 
			{
				cout << "Enter existed operation" << endl;
			}

		}
		else 
		{
			cout << "Enter existed operation" << endl;
		}
	}
	return 0;
}
