/*
Author-Shashwat Garg, 200050130
Mar 12, 2021
Improvements to Lab1 programs, CS154

Demostrating Procedural approach to calculate experimental probability of dice rolling using C.
*/


#include "stdio.h"
#include "stdlib.h"
#include <time.h>

int randomgen(){//generates random number from 1 to 6
    return rand()%6+1;
}


void newroll(int * roll_stats){//updates count for each roll
    roll_stats[randomgen()]++;
}


void showresults(int * roll_stats, int n){//displays final result
    for(int i=1; i<=6; i++){
        printf("%d: %d rolls\n",i,roll_stats[i]);
        printf("The Probability of %d is: %f\n\n",i,1.0*roll_stats[i]/n);
    }
}



int main (int argc, char *argv[]) {
	
    ::srand(time(0));
    int n=atoi(argv[1]);
    int roll_stats[7]={0,0,0,0,0,0,0};//declaration and initialisation

	if(argc!=2){//check for invalid input
	    printf("Please enter a single integer as command line input\n");
	    return 1;//error code for invalid input
	}
	
    if(n==0){//check for invalid input
	    printf("Please enter a positive integer as command line input\n");
	    return 2;//error code for invalid integer
	}

    for(int i=0; i<n; i++){
        newroll(roll_stats);//updates count for every roll
    }

    showresults(roll_stats, n);//displaying results

    return 0;
}
