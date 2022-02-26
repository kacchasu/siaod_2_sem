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
const unsigned int n = 3, m = 5; // инициализация и объявление размера массива
void random(double arr[][m]) {// процедура для заполнения маcсива случайными числами
	Sleep(1000);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = double(rand()) / double((rand() + 1));
}
void printArr(double arr[][m]) { // процедура для вывода массива
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
}
double foundD(double arr[][m]) { // функция нахождения |D|
	double D = 0;
	for (int i = 0; i < n; i++)
		D += *max_element(arr[i], arr[i] + m);
	return D;
}
void sumD(double arr1[][m], double arr2[][m], double arr3[][m]) { // функция для суммы трех матриц
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr1[i][j] = arr1[i][j] + arr2[i][j] + arr3[i][j];
}
int main()
{
	setlocale(0, "");
	double arrA[n][m]; // объявление массивов
	double arrB[n][m]; // объявление массивов
	double arrC[n][m]; // объявление массивов
	random(arrA); // инициализация массивов
	random(arrB); // ...
	random(arrC); // ...
	cout << "Ваш массив A: \n";
	printArr(arrA);
	cout << "Ваш массив B: \n";
	printArr(arrB);
	cout << "Ваш массив C: \n";
	printArr(arrC);
	double ans1 = foundD(arrA) + foundD(arrB) + foundD(arrC);
	sumD(arrA, arrB, arrC);
	double ans2 = foundD(arrA);
	cout << "Значение величины (|A| + |B| + |C|) / |A + B + C| = " << ans1 / ans2;
}
