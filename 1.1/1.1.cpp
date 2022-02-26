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
void random(int* arr, int n) { // процедура для заполнения маcсива случайными числами
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 10;
}
void printArr(int* arr, int n) { // процедура для вывода массива
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}
int main()
{
	setlocale(0, "");
	int arr[5]; // объявление массива
	int ind, n = sizeof(arr) / 4; // объявление используемых переменных
	random(arr, n); // инициализация массива
	cout << "Ваш массив: ";
	printArr(arr, n);
	cout << "Введите заданную цифру: ";
	cin >> ind;
	cout << "Индекс числа с заданной цифрой в старшем разряде: ";
	for (int i = 0; i < n; i++) // поиск числа с заданной цифрой в старшем разряде (первое такое число слева-направо)
		if (num1st(arr[i]) == ind) {
			cout << i << endl;
			break;
		}
}
