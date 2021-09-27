//program by Prof. R.K.Joshi
//for CS152, IIT Bombay
//Shashwat Garg, 200050130
//Demonstrating characteristics of operators

#include <iostream>

using namespace std;

int main()
{

    int x = 10;

    ++x = x++; // this is acceptable

    //x++ = x++;  // but this is not... why?!
    /*
    Basically, with prefix we modify the object and then return it (so it can be lvalue)
    but with postfix we return the unchanged object (i.e. a copy) and only then update it by first storing the copy in a temporary,
    updating the original object, and then returning the temporary by value.

    This whole thing is the reason as to why postfix can not be lvalue

    */
    cout << x << endl; // explain the output
    //Output is 10
    /*
    Being a postfix, rvalue passes 10 before incrementing and the value of x increases to 11.
    Now, we reach the left side of the expression the lvalue which has already been incremented to 11 gets incremented to 12 due to prefix.
    But this is of no use since the assignment operator finally does its job and assigns the passed value 10 to x.
    Thus, both the incrementation operations get sandwiched between assignment processes and finally x remains 10 as it is.
    */

    //All the output and program intricacies explained in the observations.txt file. Please refer that.
}
