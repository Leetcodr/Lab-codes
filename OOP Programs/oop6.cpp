
/*
Write C++ program using STL for sorting and searching user defined records such as Item
records (Item code, name, cost, quantity etc) using vector container.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Item
{
public:
    char name[20];
    int quantity;
    int cost;
    int code;
    bool operator==(const Item &i1)
    {
        if (code == i1.code)
            return 1;
        else
            return 0;
    }
    bool operator<(Item &i1)
    {
        if (code < i1.code)
            return 1;
        else
            return 0;
    }
};

vector<Item> v1;
void print(Item &i1);
void display();
void search();
void insert();
void dlt();

void insert()
{
    Item i1;
    cout << "Enter the Name:";
    cin >> i1.name;
    cout << "Enter the Quantity:";
    cin >> i1.quantity;
    cout << "Enter cost:";
    cin >> i1.cost;
    cout << "Enter code:";
    cin >> i1.code;
    v1.push_back(i1);
}
void display()
{
    for_each(v1.begin(), v1.end(), print);
}
void print(Item &i1)
{
    cout << "\nName :" << i1.name;
    cout << "\nQuantity :" << i1.quantity;
    cout << "\nCost :" << i1.cost;
    cout << "\nCode :" << i1.code;
}
void search()
{
    vector<Item>::iterator a;
    Item i1;
    cout << "\nEnter Item code to be search:";
    cin >> i1.code;
    a = find(v1.begin(), v1.end(), i1);
    if (a != v1.end())
        cout << "Item code is Found";
    else
        cout << "not Found";
}
void dlt()
{
    vector<Item>::iterator a;
    Item i1;
    cout << "\nEnter Item code to be deleted:";
    cin >> i1.code;
    a = find(v1.begin(), v1.end(), i1);
    if (a != v1.end())
    {
        v1.erase(a);
        cout << "Item deleted";
    }
    else
    {
        cout << "\nNot found";
    }
}

int main()
{
    int ch;
    do
    {
        cout << "\n*****MENU*****" << endl;
        cout << "1.INSERT" << endl;
        cout << "2.DISPLAY" << endl;
        cout << "3.SEARCH" << endl;
        cout << "4.SORT" << endl;
        cout << "5.DELETE" << endl;
        cout << "6.EXIT" << endl;
        cout << "Enter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            sort(v1.begin(), v1.end());
            cout << "Sorted items are :";
            display();
            break;
        case 5:
            dlt();
            display();
            break;
        case 6:
            exit(0);
        }

    } while (ch != 7);
    return 0;
}
