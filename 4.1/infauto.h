#ifndef __INFAUTO_H__
#define __INFAUTO_H__
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
struct Date
{
	int day;
	int month;
	int year;
};
struct InfAuto
{
	string number;
	string model;
	string color;
	string owner;
	Date date = { 0, 0, 0 };
};
struct SheetAuto
{
	int n = 0;
	const static int N = 100;
	InfAuto autosheet[N];
};
#endif