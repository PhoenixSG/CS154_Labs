/*
Author- Shashwat Garg
Mar 15, 2021
Lab 2, CS154

Demonstrating a single lift and it's interaction with the people as they board and leave at different floors.
Using OOP Paradigm.
Using lift and person class as abstraction
*/

#include <bits/stdc++.h>
using namespace std;


class person{

    private:
    int current_floor;
    int requested_floor;
    int up_down;            //up=1, down=-1
    int inside_outside;     //inside=1, outside=0
    int index;              //index of person in lift

    public:

    person(){
        inside_outside=0;
    }


    void set_levels(int source, int destination){
        current_floor=source;
        requested_floor=destination;
        inside_outside=0;
        if(requested_floor==current_floor){
            cout<<"You are already on the requested floor\n";   //trivial case
            this->~person();                                    //destroy the useless object
        }
        else if(requested_floor>current_floor){ //wanting to go up
            up_down=1;
        }
        else{                                   //wanting to go down
            up_down=-1;
        }
    }


    void set_index(int position);
    int get_index();
    int status();
    int get_floor();
    int get_destination();
    void get_out(int n);
    void get_in(int n);
};




class lift{

    private:
    int floor;
    person* list[5];
    int no_of_people;
    int direction;          //moving up=1, moving down=-1
    int next_stop;

    public:

    lift(int n, int d){
        floor=n;
        for(int i=0; i<5; i++){
            list[i]=NULL;
        }
        no_of_people=0;
        direction=d;
        next_stop=-1;
    }

    void add_person(person* input, int index, string* namelist);
    void remove_person(person* input, int index, string* namelist);
    int get_floor();
    void floor_management(person* people, int index, string* namelist);
    void move();
    void show();


};






    void person::get_out(int n){
        current_floor=n;
        requested_floor=-1;
        up_down=0;
        inside_outside=0;
        index=-1;
    }

    void person::get_in(int n){
        current_floor=n;
        inside_outside=1;
    }


    void person::set_index(int position){
        index=position;
    }

    int person::get_index(){
        return index;
    }

    int person::status(){
        return inside_outside;
    }

    int person::get_floor(){
        return current_floor;
    }

    int person::get_destination(){
        return requested_floor;
    }




    
    void lift::add_person(person* input, int index, string* namelist){
        if(no_of_people<5){
            list[no_of_people]=input;
            input->set_index(no_of_people);
            input->get_in(get_floor());
            no_of_people++;
            cout<<"Welcomne to the lift "<<namelist[index]<<".\n";
        }
        else{
            cout<<"Sorry "<<namelist[index]<<"! The lift is full right now, please come back later\n";
        }
    }

    void lift::remove_person(person* input, int index, string* namelist){
        if(input->status()){
            cout<<"Thank you for travelling "<<namelist[index]<<".\n";

            int position=input->get_index();
            list[position]=NULL;

            input->get_out(floor);
            for(int i=position; i<no_of_people-1; i++){
                list[i]=list[i+1];
            }
            no_of_people--;
        }
        else{
            cout<<"Error! Person not inside lift!\n";
        }

    }

    int lift::get_floor(){
        return floor;
    }

    void lift::floor_management(person* people, int index, string* namelist){
        for(int i=0; i<no_of_people; i++){
            if(list[i]->get_destination()==floor){
                remove_person(list[i], index, namelist);
            }
        }

        for(int i=0; i<index; i++){
            if(people[i].get_destination()>=0 && people[i].get_floor()==get_floor() && people[i].status()==0){
                add_person(&people[i],i,namelist);
            }
        }


        
        
    }

    void lift::move(){
        floor+=direction;
        if(floor==6){
            direction=-1;
        }
        if(floor==0){
            direction=1;
        }
    }

    void lift::show(){
        cout<<"The number of people in the lift are "<<no_of_people<<"\n";
        cout<<"The lift is currently on floor "<<floor<<" and moving ";
        if(direction==1){cout<<"up.\n";}
        if(direction==-1){cout<<"down.\n";}
    }





int main(){

    lift l1(0,1);           //floor and direction
    person people[100];
    string namelist[70];    
    int index=0;            //people array counter
    char c;

    cout<<"Welcome to my model of a lift using object-oriented programming.\n"
    <<"Please enter input as per the rules in the observations.txt file.\n";


    cin>>c;

    while(c!='q'){

        switch(c) {  

            case 'p':       //add person
                int source, destination;
                cin>>namelist[index]>>source>>destination;
                if(source<0 || source>6 ||destination<0 || destination>6){
                    cout<<"Wrong input. Please try again.\n";
                    continue;
                }

                people[index].set_levels(source, destination);
                cout<<namelist[index]<<" has entered on floor "<<source<<". He wants to go to floor "<<destination<<".\n";
                index++;

                break;

            case 'm':

                l1.move();
                l1.floor_management(people, index+1, namelist);


            default:
                ;
        }
    cin>>c;
    l1.show();
    }
    cout<<"Thank you for interacting with the system\n";


return 0;
}