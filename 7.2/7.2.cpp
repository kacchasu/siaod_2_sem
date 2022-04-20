// 7.2.cpp : Постфиксная - Массив - Вычислить значение выражения
#include "stack.h"
#include <vector>

using namespace std;

int main()
{
    string s;
    cout << "enter expression (s): ";
    getline(cin, s);
    stack w1;
    for (int i = 0; i < s.size(); i++)
    {
        if (string("0123456789").find(s[i]) != string::npos)
        {
            cout << i + 1 << ") got operand; adding in stack: " << s[i] << endl;
            w1.push(s[i] - '0');
        }
        else
        {
            int a = w1.pop();
            int b = w1.pop();
            cout << i + 1 << ") got operation; taking 2 operands from stack: " << b << " and " << a << endl;
            switch (s[i])
            {
            case '-':
                cout << "   adding " << b << " - " << a << " = " << b - a << " in stack" << endl;
                w1.push(b - a);
                break;
            case '+':
                cout << "   adding " << b << " + " << a << " = " << b + a << " in stack" << endl;
                w1.push(b + a);
                break;
            case '*':
                cout << "   adding " << b << " * " << a << " = " << b * a << " in stack" << endl;
                w1.push(b * a);
                break;
            case '/':
                cout << "   adding " << b << " / " << a << " = " << b / a << " in stack" << endl;
                w1.push(b / a);
                break;
            default:
                break;
            }
        }
    }
    cout << "answer: value expression: s = " << w1.pop() << endl;
}
