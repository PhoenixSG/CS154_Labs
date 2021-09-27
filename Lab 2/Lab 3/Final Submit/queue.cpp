/*
Author- Shashwat Garg, 200050130
Demonstrating Object Oriented Paradigm to model a queue, which operates based on user input.
*/

#include <iostream>
using namespace std;


#define capacity 1000

class Queue {

	string list[capacity];		//data storage
	int first;		//starting index
	int last;		//ending index
	int occupancy;	//no of poepole in the queue

 public:
	Queue(){
		for(int i=0; i<1000; i++){
			list[i]="0";
		}
		first=0;
		last=-1;
		occupancy=0;
	}
	void enter_person(string i); 	//inserts a new person in the queue
	void remove_person();			//removes the first person from the queue

};

void Queue::enter_person(string i){//check for edge case. Add a new person. Updates index and count
	if(occupancy==capacity){
		cout<<"Sorry! The queue is full. Please come back later./n";
		return;
	}
	last=(last+1)%capacity;
	list[last]=i;
	occupancy++;
}

void Queue::remove_person(){//check for edge case. Remove the first person. Updates index and count
	if(occupancy==0){
		cout<<"Sorry! The queue is empty. Please wait for people to arrive.\n";
		return;
	}
	cout<<list[first]<<" is exiting the queue.\n";
	list[first]="0";
	first=(first+1)%capacity;
	occupancy--;
	return;
}


int main () {
	Queue q1;		//object creation and initialisation

	char cmd; 		//manage input
	string name;	//manage input

cout<<"Hello, Welcome to Queue Management.\n"
	<<"Please press a to add a person to the list.\n"
	<<"Press r to remove the first person from the list.\n"
	<<"Press x to exit the program.\n";

cin>>cmd;

    while(cmd!='x'){

        switch(cmd) {  

            case 'a':       //add person
				cout<<"Please enter the person's name-\n";
				cin>>name;
				q1.enter_person(name);
                break;

            case 'r':		//remove person
				q1.remove_person();
				break;

            default:
                cout<<"Please follow the instructions.\n";
        }
		cout<<"Enter the next command\n";
		cin>>cmd;
	}
cout<<"Thank you for visiting!\n";

}
