//program by Prof. R.K.Joshi
//for CS152, IIT Bombay
//Updated and Improved by Shashwat Garg, 200050130
//Demonstrating characteristics of operators

#include <iostream>
using namespace std;
class A
{
	int id;

public:
	A(int v) { id = v; }

	A &operator=(A &a)
	{
		cout << "executing " << id << "=" << a.id << endl;
		id = a.id;
		return *this;
	}

	A operator+(A &a)
	{
		cout << "executing " << id << "+" << a.id << endl;
		return A(id + a.id);
	}
};
int main()
{
	int a = 1, b = 1, c = 1;

	a = (++b) = (c++);
	cout << a << b << c << endl;

	a = (++b) = (++c);
	cout << a << b << c << endl;

	++a = (b) = (c++);
	cout << a << b << c << endl;

	cout << endl;

	A a1(1), a2(2), a3(3);
	a1 = a2 = a3; //cascading, follows right to left precedence
	cout << endl;

	A b1(10), b2(100), b3(1000);
	b1 = (b2 + b3) = b3;

	cout << endl;
	b1 = b2 = b3;
}
