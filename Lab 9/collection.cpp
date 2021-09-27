//program by Prof. R.K.Joshi
//for CS152, IIT Bombay
//Updated and Improved by Shashwat Garg, 200050130
//Capturing abstractions of collections as a stack and overloading the necessary operators to make it feel natural

#include <iostream>
using namespace std;

class Collection
{

	int *array, card, maxsize; // storage and cardinality
public:
	Collection(int sz)
	{
		array = new int[sz];
		card = 0;
		maxsize = sz;
	}

	Collection &operator<<(int elem)
	{
		if (card < maxsize)
			array[card++] = elem;
		else
			cout << "Full Capacity, " << elem << " couldn't be added. Try again later\n";
		return *this;
	}

	Collection &operator>>(int &elem)
	{
		if (card > 0)
			elem = array[--card];
		else
			cout << "Empty Collection, Try again later\n";
		return *this;
	}

	Collection &operator<<(Collection c)
	{
		if (card + c.getsize() < maxsize)
		{
			for (int i = 0; i < c.getsize(); i++)
				array[card++] = c.pop();
		}
		else
		{
			cout << "Full Capacity, Try again later\n";
			cout << "Couldn't add ";
			c.prn();
		}

		return *this;
	}

	int getsize()
	{
		return card;
	}

	int pop()
	{
		card -= 1;
		return array[card];
	}
	void prn()
	{
		cout << "{ ";
		for (int i = 0; i < card; i++)
			cout << array[i] << " ";
		cout << "}";
		cout << endl;
	}
};

int main()
{

	Collection c1(10);

	c1 << 1;
	c1 << 2;
	c1 << 3;
	c1 << 4;
	c1 << 5;
	c1.prn();

	Collection c2(3);

	c2 << 6 << 7 << 8; //cascading
	c2.prn();

	c1 << c2; //bulk insertion

	int x, y;
	c2 >> x; //extraction operator
	c2.prn();
	c2 >> x;
	c2.prn();
	c2 >> x;
	c2.prn();
	c2 >> x;
	c2.prn(); //error

	c1.prn();
	c1 >> x >> y; //cascading
	c1.prn();

	cout << x << y << endl;
}
