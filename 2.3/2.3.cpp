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
int vektormulti(int ax, int ay, int bx, int by)
{
	return ax * by - bx * ay;
}
bool islinecrossed(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4)
{
	int v1 = vektormulti(p4.first - p3.first, p4.second - p3.second, p1.first - p3.first, p1.second - p3.second);
	int v2 = vektormulti(p4.first - p3.first, p4.second - p3.second, p2.first - p3.first, p2.second - p3.second);
	int v3 = vektormulti(p2.first - p1.first, p2.second - p1.second, p3.first - p1.first, p3.second - p1.second);
	int v4 = vektormulti(p2.first - p1.first, p2.second - p1.second, p4.first - p1.first, p4.second - p1.second);
	return (v1 * v2 <= 0 and v3 * v4 <= 0);

}
bool istrianglecrossed(vector<pair<int, int>> triangle1, vector<pair<int, int> > triangle2)
{
	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 3; j++)
			for (int k = 0; k < 3; k++)
				for (int m = k + 1; m < 3; m++)
					if (islinecrossed(triangle1[i], triangle1[j], triangle2[k], triangle2[m]))
						return true;
}
int main()
{
	setlocale(0, "");
	int n; // объявление используемых переменных
	cout << "Введите количество точек n: ";
	cin >> n;
	vector<pair<int, int> > arr;
	for (int i = 0; i < n; i++) {
		int fst, snd;
		cout << "Enter " << i + 1 << " point coordinates: ";
		cin >> fst >> snd;
		arr.push_back(make_pair(fst, snd));
	}
	vector<vector<pair<int, int> > > triangles;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				if ((arr[i].first - arr[k].first) * (arr[j].second - arr[k].second) !=
					(arr[i].second - arr[k].second) * (arr[j].first - arr[k].first)) {
					vector<pair<int, int> > temp;
					temp.push_back(arr[i]);
					temp.push_back(arr[j]);
					temp.push_back(arr[k]);
					triangles.push_back(temp);
					cout << "Triangle " << triangles.size() << endl;
					cout << arr[i].first << ' ' << arr[i].second << endl;
					cout << arr[j].first << ' ' << arr[j].second << endl;
					cout << arr[k].first << ' ' << arr[k].second << endl;
				}
	vector<int> crosses(triangles.size(), 0);
	int max = 0;
	int maxi = -1;
	for (int i = 0; i < triangles.size(); i++)
		for (int j = i + 1; j < triangles.size(); j++)
			if (istrianglecrossed(triangles[i], triangles[j])) {
				crosses[i]++;
				crosses[j]++;
				crosses[i] > max ? max = crosses[i], maxi = i : max = max;
				crosses[j] > max ? max = crosses[j], maxi = j : max = max;
			}
	cout << "Most-crossed triangle: A = (" << triangles[maxi][0].first << ';' << triangles[maxi][0].second << ") B = (" << triangles[maxi][1].first << ';' << triangles[maxi][1].second << ") C = (" << triangles[maxi][2].first << ';' << triangles[maxi][2].second << ')';
}
