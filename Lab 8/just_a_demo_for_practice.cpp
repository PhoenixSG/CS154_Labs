/*
	Code improved by Shashwat Garg, 200050130.
	Lab 8, CS154
	May 3, 2021
*/

#include <iostream>
//#define NDEBUG  // uncomment to turn off Assertions

#include <cassert>
using namespace std;

int main()
{
	cout<<"Enter a number between 1 and 1000000\n";
	int n;
	cin >> n;

	assert(n>0 && n<=1000000);

	int a[n];

	for (int i = 0; i <= n; i++)
	{

		assert(i < n);
		assert(i > -1);

		a[i] = i;
	}
}
