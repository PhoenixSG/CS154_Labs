/*
Author-Shashwat Garg, 200050130
Mar 12, 2021
Improvements to Lab1 programs, CS154

Demostrating OOP approach to calculate no. of occurences of alphabets in a file using C++.
*/

#include <iostream>
#include <fstream>
using namespace std;

class record{
    private:
    int occurence[256];//storing character occurences as per ASCII

    public:
    record(){
        for(int i=0; i<256; i++){
            occurence[i]=0;
        }
    }

    void upgrade(int a){//update the count
        occurence[a]++;
    }

    void display(){//present the results
        char x;
        for(int i=97; i<123; i++){
            x=i;
            cout<<x<<": "<<occurence[i]+occurence[i-32]<<endl;//sum of capital and small characters
        }
    }

};


int main(int argc, char *argv[]){

    char ch;
    record alphabet;

    char* input=argv[1];
    auto fp=fopen(input, "r");

    if(argc!=2){//check for invalid input
	    cout<<"Please enter a single filename as command line input"<<endl;
	    return 1;//error code for invalid input
	}

    if (fp == NULL) {
        cout<<"FILE NOT AVAILABLE\n\n";
        return 2;//error code for file not found
    }
    
    while ((ch = fgetc(fp)) != EOF){
        alphabet.upgrade(ch);
    }

    alphabet.display();


return 0;
}
