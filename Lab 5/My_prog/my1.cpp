/*
Author- Shashwat Garg, 200050130

Demostrating breadth of inheritance, using animals as parent class
*/


#include <iostream>
using namespace std;

class Animals
{
        string name;
public:
        Animals(string n){name=n; cout<<"Animal is a "<<name<<endl;}

        virtual void move()=0;
        virtual void eat()=0;
};

class Birds : public Animals
{
        bool wings;
        bool claws;

public:
        Birds(bool w, bool c) : Animals("Bird") {
                wings=w;
                claws=c;
        }
        virtual void move() {
                if(wings)
                cout << "The Bird flies\n";
                else
                cout<<"Flightless Bird\n";
        }
        virtual void eat() {
                if(claws)
                cout<<"Hunts for food\n";
                else
                cout<<"Eats grains, fruits\n";
        }
};

class Fish : public Animals
{
        bool fins;
        bool predator;

public:
        Fish(bool f, bool p) : Animals("Fish") {
                fins=f;
                predator=p;
        }
        virtual void move() {
                if(fins)
                cout<<"Has Fins for movement\n";
                else
                cout<<"Moves without fins\n";
        }
        virtual void eat()
        {
                if(predator)
                cout<<"Eats other fish\n";
                else
                cout<<"Eats plants and other stuff\n";
        }
};

class Mammals : public Animals
{
        int legs;
        int hands;
        bool predator;

public:
        Mammals(int l, bool p) : Animals("Mammal") {
                legs=l;
                predator=p;
        }
        virtual void move() {
                if(legs>0)
                cout<<"Has Legs for movement\n";
                else
                cout<<"Moves without legs\n";
        }
        virtual void eat()
        {
                if(predator)
                cout<<"Eats other animals\n";
                else
                cout<<"Eats plants and other stuff\n";
        }

};


int main(int argc, char *argv[])
{
        Animals *aptr;
        int x;
        bool b1, b2;
        int i1;
        
        cout<<"Hello, Which animal do you want to know about?\n";
        cout<<"Enter 1 for birds, 2 for fish and 3 for mammals\n";
        
        cin>>x;
        if(x==1){
                cout<<"Enter whether bird has wings by pressing 0 or 1\n";
                cin>>b1;
                cout<<"Enter whether bird has claws by pressing 0 or 1\n";
                cin>>b2;
                aptr=new Birds(b1, b2);
        }
        else if(x==2){
                cout<<"Enter whether fish has fins by pressing 0 or 1\n";
                cin>>b1;
                cout<<"Enter whether fish is a predator by pressing 0 or 1\n";
                cin>>b2;
                aptr=new Fish(b1, b2);
        }
        if(x==3){
                cout<<"Enter the number of legs\n";
                cin>>i1;
                cout<<"Enter whether the mammal is a predator by pressing 0 or 1\n";
                cin>>b2;
                aptr=new Mammals(i1, b2);
        }

        aptr->move();
        aptr->eat();

        return 0;
}
