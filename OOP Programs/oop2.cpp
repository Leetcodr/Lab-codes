
/*
  2)  Develop a program in C++ to create a database of student’s information system containing the
following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact
address, Telephone number, Driving license no. and other. Construct the database with
suitable member functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and dynamic
memory allocation operators-new and delete as well as exception handling.
*/

#include <iostream>
#include <string.h>
using namespace std;
class student
{
public:
	int rn;
	char clas[10];
	int srn;
	long int tele;
	char name[10];
	char BG[5];
	char div;
	char DOB[10];

	static int count;

	void getdata();
	friend void display(student &obj);

	student() // constructor
	{
		rn = 0;
		cout << "\t constructor \n";
		rn = count;
		count++;
	}
	~student() // destructor
	{
		cout << "\n destructor";
		cout << "\n destroing the object";
		count--;
	}
	static void getcount()
	{
		cout << "construstor count is " << count << endl;
	}

	student(student &obj)
	{
		rn = obj.rn;
		strcpy(name, obj.name);
		strcpy(DOB, obj.DOB);
		strcpy(BG, obj.BG);
		strcpy(clas, obj.clas);
		div = obj.div;
		tele = obj.tele;
		srn = count;
		count++;
	}
};
int student::count = 0;
void student::getdata()
{
	cout << "\n"
		 << "enter rn:";
	cin >> rn;
	cout << "\n"
		 << "enter name:";
	cin >> name;
	cout << "\n"
		 << "enter DOB:";
	cin >> DOB;
	cout << "\n"
		 << "enter BG:";
	cin >> BG;
	cout << "\n"
		 << "enter class:";
	cin >> clas;
	cout << "\n"
		 << "enter div:";
	cin >> div;
	cout << "\n"
		 << "enter tele:";
	cin >> tele;
}

void display(student &obj)
{
	cout << "\n"
		 << obj.rn;
	cout << "\t" << obj.name;
	cout << "\t" << obj.DOB;
	cout << "\t" << obj.BG;
	cout << "\t" << obj.clas;
	cout << "\t" << obj.div;
	cout << "\t" << obj.tele << endl;
}

int main()
{
	student s1;
	student s2(s1);

	student::getcount();

	cout << "\n all the detail are as below: \n";
	cout << " ROLL\t NAME\t 	DOB\t BLOOD_GROUP\t CLASS\t DIV\t PHONE\t";

	student *s[50];

	int i, n;
	cout << "\n how many student object do you want to creater?";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		s[i] = new student();
	}
	for (i = 0; i < n; i++)
	{
		s[i]->getdata();
	}
	cout << "\n"
		 << "ROLL_NO";
	cout << "\t" << "NAME";
	cout << "\t" << "DOB";
	cout << "\t" << "BLOOD_GROUP";
	cout << "\t" << "CLASS";
	cout << "\t" << "DIV";
	cout << "\t" << "PHONE";
	for (i = 0; i < n; i++)
	{
		display(*s[i]);
	}
	student::getcount();
	for (i = 0; i < n; i++)
	{
		delete (s[i]);
	}

	return 0;
}

/*
OUTPUT;
	 constructor
construstor count is 2

 all the detail are as below:
 ROLL	 NAME	 	DOB	 BLOOD_GROUP	 CLASS	 DIV	 PHONE
 how many student object do you want to creater?5
	 constructor
	 constructor
	 constructor
	 constructor
	 constructor

enter rn:08

enter name:MOHAN

enter DOB:07/10/2003

enter BG:A+

enter class:SE

enter div:A

enter tele:4557667956

enter rn:01

enter name:SAKET

enter DOB:12/10/2003

enter BG:B+

enter class:SE

enter div:A

enter tele:4357687869

enter rn:10

enter name:RITESH

enter DOB:20/06/2002

enter BG:AB+

enter class:SE

enter div:A

enter tele:3464574889

enter rn:11

enter name:ADITYA

enter DOB:17/04/2003

enter BG:B+

enter class:SE

enter div:A

enter tele:3546587698

enter rn:12

enter name:SANKALP

enter DOB:15/01/2003

enter BG:A+

enter class:SE

enter div:A

enter tele:6757688778

ROLL_NO	NAME	DOB	    BLOOD_GROUP	CLASS	DIV	PHONE
8	MOHAN	07/10/2003	A+	SE	A	4557667956

1	SAKET	12/10/2003	B+	SE	A	4357687869

10	RITESH	20/06/2002	AB+	SE	A	3464574889

11	ADITYA	17/04/2003	B+	SE	A	3546587698

12	SANKALP	15/01/2003	A+	SE	A	6757688778
construstor count is 7

 destructor
 destroing the object
 destructor
 destroing the object
 destructor
 destroing the object
 destructor
 destroing the object
 destructor
 destroing the object
 destructor
 destroing the object
 destructor*/
