/*
	Own assert defined by Shashwat Garg, 200050130.
	Lab 8, CS154
	May 3, 2021
*/

#include <iostream>
using namespace std;


#define codeassert(arg)                                            \
    if (!(arg)){                                                    \
        cout << "Error. The following is false- " << #arg <<"  ...  on line no. "<<__LINE__<< endl; \
        abort();    \
    }   \

int main()
{

    int i, j;
    cin >> i;
    cin >> j;

    codeassert(i == j);             //Depends on input
    codeassert(true);
    codeassert(false);              //Error
    codeassert(false || true);
    codeassert(true && false);      //Error
    codeassert(2);
    codeassert(0)                   //Error
}
