

/*
Imagine a publishing company which does marketing for book and audio cassette versions.
Create a class publication that stores the title (a string) and price (type float) of publications.
From this class derive two classes: book which adds a page count (type int) and tape which
adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and
displays the data members. If an exception is caught, replace all the data member values with
zero values.
*/

#include <iostream>
#include <string>
using namespace std;

class publications
{
public:
    string name;
    float price;

public:
    virtual void getdata() = 0;

    virtual void printdata() = 0;
};

class book : public publications
{

    float pages, edition;

public:
    void getdata()
    {
        cin.ignore();
        cout << "Enter name of book\n";
        getline(cin, name);

        while (true)
        {
            cout << "Enter the price of book\n";
            cin >> price;
            try
            {
                if (price > 1000)
                {
                    throw price;
                }
                break;
            }
            catch (...)
            {
                cout << "!!!PRICE MUST BE LESS THAN 1000!!!\n";
            }
        }

        while (true)
        {
            cout << "Enter the number of pages: \n";
            cin >> pages;
            try
            {
                if (pages < 0)
                {
                    throw pages;
                }
                break;
            }
            catch (...)
            {
                cout << "!!!PLEASE ENTER VALID VALUE!!!\n";
            }
        }
        cout << "Enter the edition number: \n";
        cin >> edition;
    }

    void printdata()
    {

        cout << "\n\n1.| Name of the book:  | " << name << "\n";
        cout << "2.| Price of the book: | " << price << "\n";
        cout << "3.|Pages:              | " << pages << "\n";
        cout << "4.|Edition:            | " << edition << "\n";
    }
};

class tape : public publications
{
    string voice, genre, series;
    string country;
    float Time, edition;

public:
    void getdata()
    {
        cout << "Enter name of tape\n";
        cin.ignore();
        getline(cin, name);

        while (true)
        {
            cout << "Enter the price of tape\n";
            cin >> price;
            try
            {
                if (price > 1000)
                {
                    throw price;
                }
                break;
            }
            catch (...)
            {
                cout << "!!!PRICE MUST BE LESS THAN 1000!!!\n";
            }
        }

        while (true)
        {
            cout << "Time duretion of the tape: \n";
            cin >> Time;
            try
            {
                if (Time < 0)
                {
                    throw Time;
                }
                break;
            }
            catch (...)
            {
                cout << "!!!PLEASE ENTER VALID VALUE!!!\n";
            }
        }

        cout << "Enter the edition number: \n";
        cin >> edition;
    }

    void printdata()
    {
        cout << "\n\n1.| Name of the tape:  | " << name << "\n";
        cout << "2.| Price of the tape: | " << price << "\n";
        cout << "3.|time :              | " << Time << "\n";
        cout << "4.|Edition:            | " << edition << "\n";
    }
};

int main()
{
    int i = 0, g, io;
    char choice;

    cout << "you can add upto 1000 books\n";

    book array[1000];
    tape array1[1000];

    do
    {
        cout << "Enter your choice :\n1]book\n2]display books\n3]tape\n4]display tapes\n5]exit\n";
        cin >> g;

        switch (g)
        {

        case 1:
            do
            {
                array[i].getdata();
                i++;
                cout << "Do want to add " << i + 1 << " book :(Y/N)\n";
                cin >> choice;
            } while (choice == 'Y');
            cout << "Do want to return to main menu :(Y/N)\n";
            cin >> choice;
            break;

        case 2:
            for (int p = 0; p < i; p++)
            {
                array[p].printdata();
                cout << "\n\n\n\n";
            }
            cout << "Do want to return to main menu :(Y/N)\n";
            cin >> choice;
            break;

        case 3:
            do
            {
                array1[io].getdata();
                io++;
                cout << "Do want to add " << io + 1 << " tape :(Y/N)\n";
                cin >> choice;
            } while (choice == 'Y');
            cout << "Do want to return to main menu :(Y/N)\n";
            cin >> choice;
            break;

        case 4:
            for (int p = 0; p < io; p++)
            {
                array1[p].printdata();
                cout << "\n\n\n\n";
            }
            cout << "Do want to return to main menu :(Y/N)\n";
            cin >> choice;
            break;

        case 5:
            cout << "\nMenu has been exited\n";
            choice = 'N';
            break;

        default:
            cout << "\nwrong choice\n";
            cout << "Do want to return to main menu :(Y/N)\n";
            cin >> choice;

            break;
        }

    } while (choice == 'Y');

    cout << "\n---------------------Thankyou for using this program--------------------------\n\n\n";

    return 0;
}

/*
output:
*/
