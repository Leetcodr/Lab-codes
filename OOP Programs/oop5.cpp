
/*
Write a function template for selection sort that inputs, sorts and outputs an integer array and
a float array.
*/

#include <iostream>
using namespace std;
template <class T>
T selection_sort()
{
    T a[10];
    T temp;
    for (int i = 0; i < 10; i++)
    {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "\nsorted array is:";
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << "\n";
    }
}
int main()
{
    cout << "\nEnter numbers to be sorted\n";
    cout << "\nInteger sorting..\n";
    selection_sort<int>();
    cout << "\nFloating sorting...\n";
    selection_sort<float>();
    cout << "\nstring sorting...\n";
    selection_sort<string>();
}
