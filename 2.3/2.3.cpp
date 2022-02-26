﻿#include <iostream>
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
void random(double** arr, int n, int m) {// процедура для заполнения маcсива случайными числами
	Sleep(1000);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = double(rand()) / double((rand() + 1));
}
void printArr(double** arr, int n, int m) { // процедура для вывода массива
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
}
double foundD(double** arr, int n, int m) { // функция нахождения |D|
	double D = 0;
	for (int i = 0; i < n; i++)
		D += *max_element(arr[i], arr[i] + m);
	return D;
}
double** sumD(double** arr1, double** arr2, double** arr3, int n, int m) { // функция для суммы трех матриц
	double** arr = new double* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new double[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = arr1[i][j] + arr2[i][j] + arr3[i][j];
	return arr;
}
int main()
{
	setlocale(0, "");
	int n; // объявление используемых переменных
	cout << "Введите количество точек n: " << endl;
	cin >> n;
	vector<pair<int, int> > arr;
	for (int i = 0; i < n; i++) {
		int fst, snd;
		cin >> fst >> snd;
		arr.push_back(make_pair(fst, snd)); 
	}
}
