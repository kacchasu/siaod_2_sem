// 6.2.cpp : 2.	Найти минимальное значение в однонаправленном списке
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
struct Node
{
    int val;
    Node* next;
    Node(int _val) : val(_val), next(nullptr) {};
};
struct list
{
    Node* first;
    Node* last;
    list() : first(nullptr), last(nullptr) {};
    bool is_empty()
    {
        return first == nullptr;
    }
    void push_back(int _val)
    {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }
    void print()
    {
        cout << "Your linked list: ";
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    Node* operator[] (const int index)
    {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
    int find_min()
    {
        Node* p = first;
        int min = 1000000;
        while (p)
        {
            p->val < min ? min = p->val : 0;
            p = p->next;
        }
        return min;
    }
};
int main()
{
    list l;
    int size;
    cout << "Enter size of linked list: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int tmp;
        cout << "Enter " << i + 1 << " element of list: ";
        cin >> tmp;
        l.push_back(tmp);
    }
    cout << "Minimal value of linked list is: " << l.find_min();
    return 0;
}
