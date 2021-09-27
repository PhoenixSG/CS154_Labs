#include <iostream>
using namespace std;

void assert (int condition){
    if(condition){
        return;
    }
    else 
        cout<<"Error";
}