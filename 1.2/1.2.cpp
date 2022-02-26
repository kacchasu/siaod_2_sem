#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <csignal>
#include <Windows.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <csignal>
using namespace std;
int num1st(int num) { // функция для определения первой цифры числа
	string strnum = to_string(num);
	return strnum[0] - '0';
}
void random(int* arr, int n) {// процедура для заполнения маcсива случайными числами
	srand(time(0));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 10;
}
void printArr(int* arr, int n) { // процедура для вывода массива
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}
void insertArr(int*& arr, int n, int elem, int pos) { // функйия для вставки элемента на заданную позицию
	memcpy(arr, arr, n + 1); // увеличиваем размер выделенной памяти
	int temp = 0;
	for (int i = pos; i < n; i++) { // сдвигаем элементы на 1 вправо чтобы освободить нужное место
		temp = arr[i + 1];
		arr[i + 1] = arr[pos];
		arr[pos] = temp;
	}
	arr[pos] = elem; // вставляем элемент
}
int main()
{
	setlocale(0, "");
	int ind, n, ii = 0, elem; // объявление используемых переменных
	cout << "Введите размер массива: ";
	cin >> n;
	int* arr = new int[n]; // объявление массива
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
	random(arr, n); // инициализация массива
	cout << "Ваш массив: ";
	printArr(arr, n);
	cout << "Введите значение заданной цифры: ";
	cin >> ind;
	cout << "Введите значение элемента-вставки: ";
	cin >> elem;
	for (int i = 0; i < n; i++) // цикл для поиска индекса числа у которого старшая цифра = заданной
		if (num1st(arr[i]) == ind) {
			ii = i;
			break;
		}
	insertArr(arr, n, elem, ii);
	cout << "Массив после вставки элемента на нужное место: ";
	printArr(arr, n + 1);
}
