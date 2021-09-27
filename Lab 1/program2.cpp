#include <iostream>
#include <fstream>
using namespace std;

class record{
    private:
    int occurence[256];

    public:
    record(){
        for(int i=0; i<256; i++){
            occurence[i]=0;
        }
    }

    void upgrade(int a){
        occurence[a]++;
    }

    void display(){
        char x;
        for(int i=97; i<123; i++){
            x=i;
            cout<<x<<": "<<occurence[i]<<endl;
        }
    }

};


int main(int argc, char *argv[])
{

    char ch;
    record alphabet;

    char* input=argv[1];
    auto fp=fopen(input, "r");

    if (fp == NULL) { printf("FILE NOT AVAILABLE. \nRequired file: abc.txt\n"); 
    return 1;}
    while ((ch = fgetc(fp)) != EOF) { alphabet.upgrade(ch) ;}

    alphabet.display();


return 0;
}
