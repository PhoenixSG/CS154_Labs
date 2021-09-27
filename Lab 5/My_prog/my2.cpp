/*
Author- Shashwat Garg, 200050130

Demostrating depth of inheritance and dynamic binding.
*/

#include <iostream>
using namespace std;

class A
{
    int a_element;

public:
    A(int a)
    {
        a_element = a;
    }
    virtual void show_a() { cout << a_element << endl; }
    virtual void show_b() = 0;
    virtual void show_c() = 0;
};

class B : public A
{
    int b_element;

public:
    B(int b) : A(2 * b)
    {
        b_element = b;
    }
    virtual void show_b() { cout << b_element << endl; }
    virtual void show_d() = 0;
};

class C : public B
{
    int c_element;

public:
    C(int c) : B(2 * c)
    {
        c_element = c;
    }
    virtual void show_c() { cout << c_element << endl; }
};

class D : public C
{
    int d_element;

public:
    D(int d) : C(2 * d)
    {
        d_element = d;
    }
    virtual void show_d() { cout << d_element << endl; }
};

int main(int argc, char *argv[])
{
    A *aptr;
    B *bptr;
    C *cptr;
    D *dptr;

    dptr = new D(10);
    dptr->show_a(); //All 4 statements below are valid,
    dptr->show_b(); //Since parent class functions are available in subclass.
    dptr->show_c();
    dptr->show_d();

    cout << "\n\n";

    cptr = dptr;

    cptr->show_a(); //All 4 statements are valid,
    cptr->show_b(); //Since the pointer of parent class can also store address of subclass.
    cptr->show_c(); //Further, show_d() works despite show_d() not being declared in C.
    cptr->show_d(); //This is because show_d() was declared, in turn, in parent class of C, ie. B

    cout << "\n\n";

    bptr = cptr;

    bptr->show_a(); //All 4 statements are valid,
    bptr->show_b(); //Since the pointer of parent class can also store address of subclass.
    bptr->show_c(); //Like before, show_c() works despite being declared in B
    bptr->show_d(); //This is because show_c() was declared, in turn, in parent class of B, ie. A

    cout << "\n\n";

    aptr = bptr;    
                    //bptr=aptr;  error: superclass is not a subclass

    aptr->show_a(); //Only 3 statements are valid,
    aptr->show_b(); //Since there is no declaration of show_d() in A or in any of its parent classes
    aptr->show_c(); //Thus show_d() cannot be called from A
                    //aptr->show_d();     error: ‘class A’ has no member named ‘show_d’;

    delete aptr;

    return 0;
}
