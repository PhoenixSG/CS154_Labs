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

    auto fp=fopen(argv[1], "r");

    if (fp == NULL) { printf("FILE NOT AVAILABLE\n"); }
    else { while ((ch = fgetc(fp)) != EOF) { alphabet.upgrade(ch) ;} }

    alphabet.display();


return 0;
}
