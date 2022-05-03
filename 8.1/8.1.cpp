// 8.1.cpp : сортировка пузырьком с условием айверсона
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <ctime>
using namespace std;

ostream& operator << (ostream& out, const vector<int>& array)
{
	for (int i : array)
		out << i << " ";
	out << endl;

	return out;
}

int BubbleSort(vector<int> &array)
{
	int i, j, c;
	int k = 0;

	for (i = array.size(); i > 1; i--)
	{
		k = 0;

		for (j = 1; j < i; j++)
			if (array[j] < array[j - 1])
			{
				c = array[j];
				array[j] = array[j - 1];
				array[j - 1] = c;
				k = 1;
			}

		if (k == 0) return 0;
	}
}

void random_array(vector<int>& array)
{
	srand(static_cast<unsigned int>(time(0)));
	
	for (int i = 0; i < array.size(); i++)
		array[i] = rand();

}

int main()
{
	cout << "enter array size: ";
	int size;
	cin >> size;

	vector<int> array(size);

	cout << "choose between random and keyboard input (enter: random or keyboard): ";
	string mode;
	cin >> mode;

	if (mode == "random")
		random_array(array);
	else if (mode == "keyboard")
		for (int i = 0; i < size; i++)
			cout << "enter " << i + 1 << " member: ", cin >> array[i];
	else
		cout << "incorrect mode", exit(0);

	cout << "original array: " << array;
	
	BubbleSort(array);

	cout << "sorted array: " << array;
}

