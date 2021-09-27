//program by Prof. R.K.Joshi
//for CS152, IIT Bombay
//Shashwat Garg, 200050130
//Demonstrating precedence of operators

#include <iostream>
using namespace std;

// why is there a compile time error?!
//operator precedence of << is higher than ||

int main()
{

    bool a = true, b = true;

    //cout << a || b << endl; corrected below using parentheses
    cout << (a || b) << endl;
}
