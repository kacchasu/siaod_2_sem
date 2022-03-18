#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
void redactchar(string s)
{
    string loc = " ,";
    string st = s.substr(0, s.find_first_of(loc));
    s.erase(0, s.find_first_of(loc) + 1);
    string ans = st;
    string ends = "";
    while (s.size() != 0) {
        bool ok = true;
        string temp = s.substr(0, s.find_first_of(loc));
        s.erase(0, s.find_first_of(loc) + 1);
        for (int i = 0; i < temp.size(); i++)
            if (st.find(temp[i]) == string::npos)
                ok = false;
        if (ok)
            ans += ' ' + temp;
        else
            ends += ' ' + temp;
    }
    ans += ends;
    cout << ans << endl;
}
int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    s += ' ';
    redactchar(s);
}