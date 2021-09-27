// Program by Prof. R. K. Joshi
// for CS 152
//Shashwat Garg, 200050130
// unary operator overloading: the ++ operator

#include <iostream>
using namespace std;

class A
{

	int v;

public:
	A(int x) { v = x; }
	void operator++()
	{
		cout << "prefix operator called \n\n";
	}
	void operator++(int c)
	{
		cout << ++c << endl
			 << "postfix operator called \n";
	}
};

int main()
{

	A a(11);
	++a;
	a++;
	a++;
	a++;
	a++; //no change on c, see observations.txt
}
