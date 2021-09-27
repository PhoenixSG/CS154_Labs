/*
Author- Shashwat Garg, 200050130
Demonstrating Procedural Approach to model a single stack
*/

#include <iostream>
using namespace std;

//Declarations
void push (int elem); // add an element on top of stack
int pop ();  // note the value at the top, remove the top and return the value 
int card(); // return cardinality, how many elements in stack 

//Variable Declarations
int S[100];//stores the data
int top=0;//indicates the top position and acts as cardinality measurer as well. We don't need 2 variables for the same


void push(int elem) {//insert an element and update count
    S[top]=elem;
    top++;
};

int pop(){  //no need to empty stack, new value will automatically override old result if required
    top--;
    return S[top];
}

int card(){ //return no of elements
    return top;
}
//User begins

int main () { //User of the object, no functions declared here
int e;
    push(10);
    push(12);
    push(14);
    e=pop();
    cout<<e<<endl;
    e=pop();
    cout<<e<<endl;
    e=card();
    cout<<"No of elements in stack are "<<e<<endl;
}
