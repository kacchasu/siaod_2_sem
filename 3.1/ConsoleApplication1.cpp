#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
void redactchar(char * si)
{
    char s2[] = " ,.!";
    char* s = strtok(si, s2);
    char st[1000] = "";
    strcpy(st, s);
    char begins[1000] = "";
    strcat(begins, st);
    char ends[1000] = "";
    while (s != NULL)//пока не достигнем конца строки (\0 или NULL)
    {
        bool ok = true;
        s = strtok(NULL, s2);	//указатель на слово между \0 и символом разделителем
        if (s != NULL) {
            for (int i = 0; i < strlen(s); i++)
                if (s[i] != '\0' and strchr(st, s[i]) == 0)
                    ok = false;
            if (ok) {
                strcat(begins, " ");
                strcat(begins, s);
            }
            else {
                strcat(ends, " ");
                strcat(ends, s);
            }
        }
    }
    strcat(begins, ends);
    cout << begins;
}
int main()
{
    setlocale(0, "");
    char si[1000];
    cout << "Enter string: ";
    gets_s(si);  
    redactchar(si);
}