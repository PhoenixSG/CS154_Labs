//program by Prof. R.K.Joshi
//for CS152, IIT Bombay
//Updated and Improved by Shashwat Garg, 200050130
//Demonstrating characteristics of operators

#include <iostream>

using namespace std;

void f(int x, int y, int z)
{

    cout << "function part-  " << x << " " << y << " " << z << endl;
}

int main()
{
    int i = 10;
    cout << i << endl;
    cout << "cout part-  " << i << " " << i++ << " " << ++i << endl;
    i = 10;
    cout << i << endl;

    f(i, i++, ++i);
    cout << i << endl
         << endl;
    i = 100;
    cout << i << endl;

    cout << "cout part-  " << ++i << " " << i++ << " " << ++i << endl;
    i = 100;
    cout << i << endl;

    f(++i, i++, ++i);

    cout << i << endl;
}
