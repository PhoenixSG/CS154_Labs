/*
Author-Shashwat Garg, 200050130
Mar 12, 2021
Improvements to Lab1 programs, CS154

Demostrating Procedural approach to calculate no. of occurences of alphabets in a file using C.
*/


#include "stdio.h"
#include "stdlib.h"

void upgrade(int a, int occurence[]){//update the count
    occurence[a]++;
}

void display(int occurence[]){//present the results
    char x;
    for(int i=97; i<123; i++){
        x=i;
        printf("%c: %d\n",x,occurence[i]+occurence[i-32]);//sum of capital and small characters
    }
}



int main(int argc, char *argv[]){

    char ch;
    int occurence[256];//storing character occurences as per ASCII

    for(int i=0; i<256; i++){
        occurence[i]=0;
    }

    char* input=argv[1];
    auto fp=fopen(input, "r");

    if(argc!=2){//check for invalid input
	    printf("Please enter a single filename as command line input\n\n");
	    return 1;//error code for invalid input
	}

    if (fp == NULL) {
        printf("FILE NOT AVAILABLE\n\n");
        return 2;//error code for file not found
    }
    
    while ((ch = fgetc(fp)) != EOF){
        upgrade(ch,occurence);//update the count
    }


    display(occurence);//present the results

return 0;
}
