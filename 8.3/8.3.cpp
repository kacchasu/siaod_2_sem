// 8.3.cpp : сортировка слиянием
//

#include <iostream>
#include <vector>
using namespace std;


ostream& operator << (ostream& out, const vector<int>& array)
{
    for (int i : array)
        out << i << " ";
    out << endl;

    return out;
}

void random_array(vector<int>& array)
{
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < array.size(); i++)
        array[i] = rand();
}

void merge(vector<int> &a, int left, int mid, int right)
{
    int it1 = 0, it2 = 0;
    vector<int> result(right - left);

    while (left + it1 < mid and mid + it2 < right)
    {
        if (a[left + it1] < a[mid + it2])
        {
            result[it1 + it2] = a[left + it1];
            it1 += 1;
        }
        else
        {
            result[it1 + it2] = a[mid + it2];
            it2 += 1;
        }
    }
    while (left + it1 < mid)
    {
        result[it1 + it2] = a[left + it1];
        it1 += 1;
    }

    while (mid + it2 < right)
    {
        result[it1 + it2] = a[mid + it2];
        it2 += 1;
    }

    for (int i = 0; i < it1 + it2; i++)
        a[left + i] = result[i];


}
void mergeSort(vector<int>& a, int left, int right)
{
    if (left + 1 >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);

}

int main()
{
    cout << "enter array size: ";
    int size;
    cin >> size;

    vector<int> array(size);

    cout << "choose between random and keyboard input (enter: random or keyboard): ";
    string mode;
    cin >> mode;

    if (mode == "random")
        random_array(array);
    else if (mode == "keyboard")
        for (int i = 0; i < size; i++)
            cout << "enter " << i + 1 << " member: ", cin >> array[i];
    else
        cout << "incorrect mode", exit(0);

    cout << "original array: " << array;

    mergeSort(array, 0, array.size());

    cout << "sorted array: " << array;
}
