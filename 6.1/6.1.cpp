// 6.1.cpp : 1.	Проверить баланс скобок в арифметическом выражении, которое передано как строка.

#include <iostream>
#include <string>
#include <fstream> 
#include <algorithm>
using namespace std;
static const string kinds = "()";
bool checker(string s, int counter = 0)
{
    if (counter < 0) return false;
    for (int i = 0; i < s.size(); i++)
        switch (s[i])
        {
        case '(': return checker(s.substr(1), counter + 1);
        case ')': return checker(s.substr(1), counter - 1);
        default: return checker(s.substr(1), counter);
        }
    return (counter == 0);
}

int main()
{
    string staple;
    cout << "Enter expression: ";
    getline(cin, staple);
    if (checker(staple))
        cout << "staples in expression: " << staple << " is balanced";
    else
        cout << "staples in expression: " << staple << " is not balanced";
}
