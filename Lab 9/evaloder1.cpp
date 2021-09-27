//program by Prof. R.K.Joshi
//for CS152, IIT Bombay
//Updated and Improved by Shashwat Garg, 200050130
//Demonstrating characteristics of operators

#include <iostream>
using namespace std;

int p = 1;

int f(int i)
{
    p = p + i;
    cout << endl;
    return p;
}

int main()
{

    cout << f(p) << f(p) << f(p) << f(++p) << endl;
    p = 1;
    cout << f(p) << f(++p) << f(p++) << f(++p) << endl;
    p = 1;
    cout << f(p--) << f(--p) << f(p--) << f(--p) << endl;
    p = 1;
    cout << f(p++) << f(--p) << f(p--) << f(--p) << endl;
}
