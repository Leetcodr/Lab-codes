
/*Implement a class Complex which represents the Complex Number data type. Implement the
following
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overload operator+ to add two complex numbers.
3. Overload operator* to multiply two complex numbers.
4. Overload operators << and >> to print and read Complex Numbers.*/

#include <iostream>
using namespace std;

class complex
{
public:
	float real;
	float imag;

	complex()
	{
		real = 0;
		imag = 0;
	}
	friend istream &operator>>(complex &in, complex &c);
	friend ostream &operator<<(complex &out, complex &c);
	complex operator+(complex t);
	complex operator*(complex t);
};
ostream &operator>>(istream &in, complex &c)
{
	cout << "\nEnter real and imaginary parts of number:";
	in >> c.real;
	in >> c.imag;
}

ostream &operator<<(ostream &out, complex &c)
{
	cout << "\nThe complex no is:";
	out << c.real << "+" << c.imag << "i\n";
}

complex complex::operator+(complex c2)
{
	complex temp;
	temp.real = real + c2.real;
	temp.imag = imag + c2.imag;
	return temp;
}
complex complex::operator*(complex c2)
{
	complex temp;
	temp.real = (real * c2.real) - (imag * c2.imag);
	temp.imag = (real * c2.imag) + (c2.real * imag);
	return temp;
}

int main()
{
	complex c1, c2, c3;

	cout << "\nFOR 1ST COMPLEX NO";
	cin >> c1;
	cout << c1;

	cout << "\nFOR 2ND COMPLEX NO";
	cin >> c2;
	cout << c2;

	int choice;
	char ch;

	do
	{

		cout << "\n----------------*MENU*-------------------\n1.ADDITION \n2.MULTIPLICATION \n-----------------------------------------\n";
		cout << "ENTER THE OPERATION WHICH IS TO BE PERFORMED:";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\n PERFORMING C1 + C2";
			c3 = c1 + c2;
			cout << c3;
			break;
		case 2:
			cout << "\n PERFORMING C1 * C2";
			c3 = c1 * c2;
			cout << c3;
			break;

		default:
			cout << "INVALID CHOICE";
		}
		cout << "\ndo you want to return menu(Y/N):";
		cin >> ch;
	} while (ch == 'Y' | ch == 'y');

	return 0;
}

/*Output:
FOR 1ST COMPLEX NO
Enter real and imaginary parts of number:33
44

The complex no is:33+44i

FOR 2ND COMPLEX NO
Enter real and imaginary parts of number:55
66

The complex no is:55+66i

----------------*MENU*-------------------
1.ADDITION
2.MULTIPLICATION
-----------------------------------------
ENTER THE OPERATION WHICH IS TO BE PERFORMED:1

 PERFORMING C1 + C2
The complex no is:88+110i

do you want to return menu(Y/N):Y

----------------*MENU*-------------------
1.ADDITION
2.MULTIPLICATION
-----------------------------------------
ENTER THE OPERATION WHICH IS TO BE PERFORMED:2

 PERFORMING C1 * C2
The complex no is:-1089+4598i

do you want to return menu(Y/N):n
*/
