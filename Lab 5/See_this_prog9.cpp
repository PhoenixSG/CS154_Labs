#include <iostream>
using namespace std;
class A
{
        int x;

public:
        A(int v) { x = v; }
        virtual void f()
        {
                cout << x << "A::f\n";
                g();
        }
        virtual void g() { cout << x << "A::g\n"; }
};
class B : public A
{
        int y;

public:
        B(int v) : A(v + 10) { y = v; }
        virtual void f() { cout << y << "B::f\n"; }
        virtual void g() { cout << y << "B::g\n"; }
};
class C : public B
{
        int z;

public:
        C(int v) : B(v + 10) { z = v; }
        virtual void f() { cout << z << "C::f\n"; }
        virtual void k()
        {
                f();
                cout << z << "C::k\n";
                f();
        }
};
int main(int argc, char *argv[])
{
        A *ap;
        B *bp;
        C *cp;

        cp = new C(10);
        cp->f();
        cp->g();
        cp->k();
        bp = new B(100);
        bp->f();
        bp->g();
        delete bp;
        bp = cp;
        bp->f();
        bp->g();
        ap = new A(200);
        ap->f();
        ap->g();
        delete ap;
        ap = bp;
        ap->f();
        ap->g();

        //New stuff added after this
        A lala = *(C *)cp;      //This is casting a pointer of type C* to B*.
                                //Then dereferencing it to object. This dereference makes it an object of the clas corresponding to the type of the pointer
                                //Then assigning the object to an object of class A. (B can be assigned to A but not vice-versa)
                                //The assignment is possible since B is-a A.
                                //The object is a pure A object now, no other class' member functions are called
                                
                                //This is not the case when we access via pointer of superclass.
                                //Then, the functions of the object class are only called, in case the superclass functions are virtual.
                                
        A hehe=* cp;				//This is also valid since, assignment operator does the type-casting
        cout << "\n\n\n";

        lala.f();
        lala.g();
        //   lala.k();
        
        //No dynamic binding, without virtual. The pointer classes definition is used
        

        A* var= new C(23);      //This is also allowed, for obvious reasons. Because C* pointer can be assigned to A* pointer

}
