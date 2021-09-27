/*
Author- Shashwat Garg, 200050130
Demonstrating Object Oriented Approach to model stacks. Using classes to organise data and member functions.

Further demostrating the encapsulation and neatness obtained which was not available earlier
OOP greatly simplifies the program to the mnost crucial abstractions and mimics real life objects in a commendable manner.
*/

#include <iostream>
using namespace std;


class Stack {
int S[100]; // S[45] is 46th element!
int top=0; // current position in stack which is empty, position indicator

public:
  void push (int elem) ;// add an element on top of stack
  int pop ();  // note the value at the top, remove the top and return the value 
  int card(); // cardinality, how many elements in stack 
};


void Stack::push(int elem) {//insert an element and update count
    S[top]=elem;
    top++;
};

int Stack::pop(){  //no need to empty stack, new value will automatically override old result if required
    top--;
    return S[top];
}

int Stack::card(){ //return no of elements
    return top;
}


//User begins

int main () { //User of the object, no functions declared here

Stack s1, s2;
  int e;

    s1.push (10);
    s1.push(12);
    s1.push (14);

    e=s1.pop();
    cout<<e<<endl;

    e=s1.pop();
    cout<<e<<endl;

    s2.push (45);
    s2.push(675);
    s2.push (5);

    e=s2.pop();
    cout << e << endl;
    e=s2.pop();
    cout << e << endl;

    e=s1.card();
    cout<<"No of elements in stack 1 are "<<e<<endl;
    e=s2.card();
    cout<<"No of elements in stack 2 are "<<e<<endl;
}
