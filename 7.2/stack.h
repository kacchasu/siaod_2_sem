#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class stack
{
public:
	vector<int> st;
	stack() {};
	void push(int x) { st.push_back(x); }
	int pop() 
	{ 
		int temp;
		temp = st[st.size() - 1];
		st.erase(st.begin() + st.size() - 1);
		return temp;
	}
};
#endif