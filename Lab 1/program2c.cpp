#include <iostream>
#include <fstream>
using namespace std;

//Procedural code

    void upgrade(int a, int occurence[]){
        occurence[a]++;
    }

    void display(int occurence[]){
        char x;
        for(int i=97; i<123; i++){
            x=i;
            cout<<x<<": "<<occurence[i]<<endl;
        }
    }



int main()
{

    char ch;
    int occurence[256];

    for(int i=0; i<256; i++){
        occurence[i]=0;
    }


    auto fp=fopen("abc.txt", "r");

    if (fp == NULL) { printf("FILE NOT AVAILABLE\nRequired file: abc.txt\n"); }
    else { while ((ch = fgetc(fp)) != EOF) { upgrade(ch,occurence) ;} }

    display(occurence);


return 0;
}
