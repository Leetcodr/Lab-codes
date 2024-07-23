
/*
Write a C++ program that creates an output file, writes information to it, closes the file, open
it again as an input file and read the information from the file.
*/

#include <iostream>
#include <fstream>
using namespace std;
// writing mode
int main()
{
    ofstream fout("Mohan.txt");
    char name[50];
    int roll_no;
    char address[60];
    char ch;
    do
    {

        cout << "enter the roll no:";
        cin >> roll_no;
        fout << roll_no << "\t |";
        cout << "enter the name:";
        cin.ignore();
        cin.getline(name, 50);
        fout << name << "\t\t |";
        cout << "enter the address:";
        cin.getline(address, 50);
        fout << address << "\n";

        cout << "do you want to add more person(Y/N):";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}
