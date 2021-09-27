/*
Author- Shashwat Garg, 200050130
Demonstrating Procedural Approach to model stacks. Using structs to organise data and pass whole dataset as argument.
Basically demostrating encapsulation and neatness obtained which was not available earlier.
*/

#include <iostream>
using namespace std;

//Interface of the abstraction, The whole struct is an abstraction for the data of stack.
//Declarations

struct Stackdata {
int S[100];//stores the data
int top=0;//indicates the top position and acts as cardinality measurer as well.
};

//Function declaration. Abstractions for operable functions

void push (int elem, Stackdata* object) ;// add an element on top of stack
int pop ( Stackdata* object);  // note the value at the top, remove the top and return the value 
int card( Stackdata* object); // cardinality, how many elements in stack 



void push (int elem, Stackdata* object){//insert an element and update count

    object->S[object->top]=elem;
    (object->top)++;
};

int pop( Stackdata* object){  //no need to empty stack, new value will automatically override old result if required
    (object->top)--;
    return object->S[object->top];
}

int card( Stackdata* object){//return no of elements
    return object->top;
}

//User begins

int main () { //User of the object, no functions declared here

Stackdata s1, s2;

    int e;
    
    push (10, &s1);
    push (12, &s1);
    push (1, &s2);
    push (20, &s2);
    push (134, &s1);
    

    e=pop(&s1);
    cout<<e<<endl;
    e=pop(&s2);
    cout<<e<<endl;
    e=pop(&s1);
    cout<<e<<endl;

    push (65, &s1);
    push (23, &s2);
    push (12, &s1);
    push (187, &s2);


    e=pop(&s2);
    cout<<e<<endl;
    e=pop(&s1);
    cout<<e<<endl;
    e=pop(&s2);
    cout<<e<<endl;


    e=card(&s1);
    cout<<"No of elements in stack 1 are "<<e<<endl;

    e=card(&s2);
    cout<<"No of elements in stack 2 are "<<e<<endl;

}
