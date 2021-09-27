//program by Prof. R.K.Joshi
//for CS152, IIT Bombay
//Updated and Improved by Shashwat Garg, 200050130
//Demonstrating use of array with exceptions for illegal access or unsupported data.

#include <iostream>
using namespace std;

class OutofBound
{
	int e;

public:
	OutofBound(int e)
	{
		this->e = e;
	}

	void msg()
	{
		switch (e)
		{
		case 0:
			cout << "Error code 0: array underflow access\n";
			break;
		case 1:
			cout << "Error code 1: array overflow access\n";
			break;
		case 2:
			cout << "Error code 2: array lower value limit\n";
			break;
		case 3:
			cout << "Error code 3: array upper value limit\n";
			break;
		}
	}
};

class Collection
{

	int array[10];

public:
	Collection()
	{
		for (int i = 0; i < 10; i++)
		{
			array[i] = 0;
		}
	}

	int &operator[](int i)
	{
		if (i >= 10)
			throw OutofBound(1);
		if (i < 0)
			throw OutofBound(0);

		return (array[i]);
	}

	void set_value(int index, int value)
	{

		if (value < -3000)
			throw OutofBound(2);
		if (value > 3000)
			throw OutofBound(3);
		array[index] = value;
	}
	void prn()
	{
		for (int i = 0; i < 10; i++)
			cout << array[i] << " ";
		cout << endl;
	}
};

int main()
{

	Collection c;

	for (int i = -1; i < 11; i++)
	{
		try
		{
			c[i] = i; //exception for -1 and 11
		}

		catch (OutofBound e)
		{
			e.msg();
		}
	}
	c.prn();
	for (int i = 0; i <= 10; i++)
	{
		try
		{
			c.set_value(i, (i - 5) * 1000); //exception for 0, 1, 9 and 10
		}

		catch (OutofBound e)
		{
			e.msg();
		}
	}
	c.prn();
}
