//program by Prof. R.K.Joshi
//for CS152, IIT Bombay
//Updated and Improved by Shashwat Garg, 200050130
//Demonstrating characteristics of operators

#include <iostream>
using namespace std;

void f(int x, int y)
{

    cout << x << " " << y << endl;
    cout << x++ << " " << y++ << " " << ++y << endl;
    cout << x << " " << y << endl;
    cout << x++ << " " << x << endl;
    cout << x << " " << y << endl
         << endl;
}

int main()
{
    int i = 10;

    f(i, i++);
    cout << i << endl
         << endl;

    // i = 100;

    f(++i, i++);

    cout << i << endl
         << endl;

    f(++i, ++i);

    cout << i << endl;
}
