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
    Node* find(int _val) 
    {
        Node* p = first;
        while (p && p->val != _val) p = p->next;
        return (p && p->val == _val) ? p : nullptr;
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
    void insert(int _val, int i)
    {
        Node* fast = new Node(_val);
        fast->next = (*this)[i];
        (*this)[i - 1]->next = fast;
    }
    void delete_even()
    {
        int i = 0;
        int c2 = 0;
        while ((*this)[i])
        {
            if (c2 == 0)
            {
                Node* p = first;
                first = p->next;
                delete p;
                c2++;
                continue;
            }
            if (c2 % 2 == 0)
            {
                if ((*this)[i])
                {
                    Node* p = (*this)[i];
                    (*this)[i - 1]->next = (*this)[i]->next;
                    delete p;
                    c2++;
                    continue;
                }
            }
            i++;
            c2++;
        }
    }
    void insert_pairs()
    {
        int i = 0;
        while (true)
            if ((*this)[i] and (*this)[i + 1])
            {
                i += 2;
                (*this).insert((*this)[i - 1]->val + (*this)[i - 2]->val, i);
                i++;
            }
            else break;
    }
};
list fusion(list L1, list L2)
{
    list L;
    int i = 0;
    while (L1[i])
        L.push_back(L1[i]->val), i++;
    i = 0;
    while (L2[i])
    {
        if (!L.find(L2[i]->val))
            L.push_back(L2[i]->val);
        i++;
    }
    return L;
}
int main()
{
    list L1, L2;
    cout << "Enter amount of nodes for L1: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cout << "Enter " << i + 1 << " node in L1: ";
        cin >> tmp;
        L1.push_back(tmp);
    }
    cout << "Enter amount of nodes for L2: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cout << "Enter " << i + 1 << " node in L2: ";
        cin >> tmp;
        L2.push_back(tmp);
    }
    cout << "L1 - ";
    L1.print();
    cout << "L2 - ";
    L2.print();
    cout << "L (fusion of L1 and L2) - ";
    fusion(L1, L2).print();
    L1.delete_even();
    cout << "L1 (even positions deleted) - ";
    L1.print();
    L2.insert_pairs();
    cout << "L2 (pair sums inserted) - ";
    L2.print();
    return 0;
}
