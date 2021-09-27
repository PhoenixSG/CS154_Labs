//program by Prof. R.K.Joshi
//for CS152, IIT Bombay
//Updated and Improved by Shashwat Garg, 200050130
//Capturing abstractions of complex numbers in math and overloading the necessary operators to make it feel natural

#include <iostream>
using namespace std;

class Complex
{
	double i, j;

public:
	Complex(double x, double y)
	{
		i = x;
		j = y;
	}

	Complex operator+(Complex c)
	{
		cout << "Operation being done-> (" << i << "," << j << ") + (" << c.i << "," << c.j << ")" << endl;
		return Complex(i + c.i, j + c.j);
	}

	Complex operator-(Complex c)
	{
		cout << "Operation being done-> (" << i << "," << j << ") - (" << c.i << "," << c.j << ")" << endl;
		return Complex(i - c.i, j - c.j);
	}

	Complex operator*(Complex c)
	{
		cout << "Operation being done-> (" << i << "," << j << ") * (" << c.i << "," << c.j << ")" << endl;
		return Complex(i * c.i - j * c.j, c.i * j + i * c.j);
	}

	Complex operator/(Complex c)
	{
		cout << "Operation being done-> (" << i << "," << j << ") / (" << c.i << "," << c.j << ")" << endl;
		return Complex((i * c.i + j * c.j) / (c.i * c.i + c.j * c.j), (c.i * j - i * c.j) / (c.i * c.i + c.j * c.j));
	}

	void prn() { cout << "( " << i << " , " << j << " )" << endl; }
};

int main()
{

	Complex c1(3.14, 2.78), c2(30, 20), c3(5, 50);

	c3 = c1 + c2;

	c3.prn();

	c3 = c3 + c1 + c2 + c2; //cascading

	c3.prn();

	c3 = c2 - c1;

	c3.prn();

	c2 = c3 * c1;

	c2.prn();

	c1 = c2 * c1 + c3; //precedence

	c1.prn();

	c1 = c2 / c3;

	c1.prn();

	c1 = c2 / c1 / c3; //associativity

	c1.prn();
}
