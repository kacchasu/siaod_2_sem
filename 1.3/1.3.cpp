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
void random(vector<int>& arr, int n) {// процедура для заполнения маcсива случайными числами
	arr.assign(n, '0');
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 10;
}
void printArr(vector<int> arr, int n) { // процедура для вывода массива
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}
int main()
{
	setlocale(0, "");
	vector<int> arr; // объявление массива
	int ind, n; // объявление используемых переменных
	cout << "Введите размер вектора: ";
	cin >> n;
	random(arr, n); // инициализация массива случайными значениями
	cout << "Ваш массив: ";
	printArr(arr, n);
	cout << "Введите заданную цифру: ";
	cin >> ind;
	int temp = 0;
	for (int i = 0; i < n; i++) // поиск чисел с заданной цифрой в старшем разряде и удаление их из массива
		if (num1st(arr[i - temp]) == ind) {
			arr.erase(arr.begin() + i - temp);
			temp++;
		}
	cout << "Массив с удаленными значениями: ";
	printArr(arr, arr.size());
}
