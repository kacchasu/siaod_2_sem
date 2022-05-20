#include <iostream>
#include <regex>
using namespace std;

int main() {
	const string input = "ABC:1->  abcde kekw PQR:2;;;   XYZ:3<<<"s;
	cout << "text: " << input << endl;
	cout << "enter phrase to search: ";
	string phrase;
	cin >> phrase;
	const regex r(phrase);
	smatch m;
	if (regex_search(input, m, r))
		cout << "phrase had found";
	else cout << "no such phrase";
	return 0;
}