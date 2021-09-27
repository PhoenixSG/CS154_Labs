/*
Author- Shashwat Garg
Mar 15, 2021
Lab 2, CS154

Demonstrating 
*/

#include <bits/stdc++.h>
using namespace std;

class floor_stats{};
class person{};

class lift{

    private:
    int floor;
    person* list[5];
    int no_of_people;
    int direction;
    int destination;
    int next_stop;

    public:

    lift(){
        floor=0;
        for(int i=0; i<5; i++){
            list[i]=NULL;
        }
        no_of_people=0;
        direction=1;
        destination=-1;
        next_stop=-1;
    }

    void add_person(person* input){
        if(no_of_people<5){
            list[no_of_people]=input;
            input->set_index(no_of_people);
            input->get_in(this);
            no_of_people++;
        }
        else{
            cout<<"Sorry! The lift is full right now, please come back later\n";
        }
    }

    void remove_person(person* input){
        if(input->status()){
        int position=input->get_index();
        list[position]=NULL;

        input->get_out(this);
        for(int i=position; i<no_of_people-1; i++){
            list[i]=list[i+1];
        }
        no_of_people--;
        }
        else{
            cout<<"Error! Person not inside lift!\n";
        }

    }

    int get_floor(){
        return floor;
    }

    void floor_management(){
        for(int i=0; i<no_of_people; i++){
            if(list[i]->get_destination()==floor){
                remove_person(list[i]);
            }
        }
        //get_in()
    }

};




class person{

    private:
    int current_floor;
    int requested_floor;
    int up_down;            //up=1, down=-1
    int inside_outside;     //inside=1, outside=0
    int index;

    public:

    person(int source, int destination){
        current_floor=source;
        requested_floor=destination;
        inside_outside=0;
        if(requested_floor=current_floor){
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

    void get_in(lift *lift_name){
        


    }

    void get_out(lift *lift_name){
        int position=lift_name->get_floor();
        current_floor=position;
        requested_floor=-1;
        up_down=0;
        inside_outside=0;
        index=-1;
    }


    void set_index(int position){
        index=position;
    }

    int get_index(){
        return index;
    }

    int status(){
        return inside_outside;
    }

    int get_floor(){
        return current_floor;
    }

    int get_destination(){
        return requested_floor;
    }

};

class floor_stats{

    private:
    int waiting[7][10];
    
};









int main(){

    int n, t;







    return 0;
}