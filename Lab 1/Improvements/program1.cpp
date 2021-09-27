/*
Author-Shashwat Garg, 200050130
Mar 12, 2021
Improvements to Lab1 programs, CS154

Demostrating OOP approach to calculate experimental probability of dice rolling using C++.
*/

#include <bits/stdc++.h>
using namespace std;


class dice{
private:
    int roll_stats[7];//To maintain uniformity, the 0th index if left unused
	int n;
public:
    dice(int input){//constructor initialises array
        for(int i=1; i<7; i++){
            roll_stats[i]=0;
        }
        n=input;
    }

    int randomgen(){//generates random number from 1 to 6
        return rand()%6+1;
    }

    void newroll(){//updates count
       roll_stats[randomgen()]++;
    }

    void showresults(){//displays final result
        for(int i=1; i<=6; i++){
            cout<<i<<": "<<roll_stats[i]<<" rolls"<<endl;
            cout<<"The Probability of "<<i<<" is: "<<1.0*roll_stats[i]/n<<endl<<endl;
        }
    }

};


int main (int argc, char *argv[]) {
	
    ::srand(time(0));
    int n=atoi(argv[1]);
    dice d1(n);
	
	if(argc!=2){//check for invalid input
	    cout<<"Please enter a single integer as command line input"<<endl;
	    return 1;//error code for invalid input
	}
	
    if(n==0){//check for invalid input
    	cout<<"Please enter a positive integer as command line input"<<endl;
    	return 2;//error code for invalid input
	}

    for(int i=0; i<n; i++){
        d1.newroll();
    }

    d1.showresults();

    return 0;
}
