/*
Author- Shashwat Garg, 200050130
Demonstrating Procedural Approach to model two stacks
*/


#include <iostream>
using namespace std;


//Interface of the abstraction 
//Declarations

void push (int elem, int *S, int *top); // add an element on top of stack
int pop (int *S, int *top);  // note the value at the top, remove the top and return the value 
int card(int *S); // returns cardinality, how many elements in stack 

//Implementation of the abstraction--
//Definitions


int S1[100]; //stores the dataset 1
int top1=0; //indicates the top position and acts as cardinality measurer as well.

int S2[100]; //stores the dataset 2
int top2=0; //indicates the top position and acts as cardinality measurer as well.


void push(int elem, int *S, int *top) {//insert an element and update count
    S[*top]=elem;
    (*top)++;
};

int pop(int *S, int *top){  //no need to empty stack, new value will automatically override old result if required
    (*top)--;
    return S[*top];
}

int card(int *top){//return no of elements
    return *top;
}

//User begins

int main () { //User of the object, no functions declared here
    
    int e;
    
    push (10, S1, &top1);
    push (12, S1, &top1);
    push (1, S2, &top2);
    push (20, S2, &top2);
    push (134, S1, &top1);
    

    e=pop(S1, &top1);
    cout<<e<<endl;
    e=pop(S2, &top2);
    cout<<e<<endl;
    e=pop(S1, &top1);
    cout<<e<<endl;

    push (65, S1, &top1);
    push (23, S2, &top2);
    push (12, S1, &top1);
    push (187, S2, &top2);


    e=pop(S2, &top2);
    cout<<e<<endl;
    e=pop(S1, &top1);
    cout<<e<<endl;
    e=pop(S2, &top2);
    cout<<e<<endl;


    e=card(&top1);
    cout<<"No of elements in stack 1 are "<<e<<endl;

    e=card(&top2);
    cout<<"No of elements in stack 2 are "<<e<<endl;

}
