// 8.2.cpp : сортировка шелла со смещением убывающим вдвое
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

void shellSort(vector<int>& numbers)
{
    int size = numbers.size();
    int increment = 3;  // начальное приращение сортировки
    // пока существует приращение
    while (increment > 0)
    {
        for (int i = increment; i < size; i++)
        {
            int j = i;  // сохраняем индекс и элемент
            int temp = numbers[i];
            // просматриваем остальные элементы массива, отстоящие от j-ого
            // на величину приращения
            while ((j >= increment) && (numbers[j - increment] > temp))
            {   // пока отстоящий элемент больше текущего
                numbers[j] = numbers[j - increment];    // перемещаем его на текущую позицию
                j = j - increment;  // переходим к следующему отстоящему элементу
            }
            numbers[j] = temp;  // на выявленное место помещаем сохранённый элемент
        }
        if (increment > 1)  // делим приращение на 2
            increment /= 2;
        else
            break;
    }
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

    shellSort(array);

    cout << "sorted array: " << array;
}
