#include <bits/stdc++.h>
using namespace std;

//Procedural approach


int randomgen(){
    return rand()%6+1;
}

struct dice{
    int roll_stats[100];
    int index;
    int result[6];
};


    void initialise(struct dice *d){
        for(int i=0; i<100; i++){
            d->roll_stats[i]=0;
        }
        d->index=0;
        for(int i=0; i<6; i++){
            d->result[i]=0;
        }
    }


    void newroll(struct dice *d){
        d->roll_stats[d->index]=randomgen();
        d->index++;
    }

    void calculateresults(struct dice *d){
        for(int i=0; i<d->index; i++){
            d->result[d->roll_stats[i]-1]++;
        }
    }

    void showresults(struct dice *d){
        for(int i=1; i<=6; i++){
            cout<<i<<": "<<d->result[i-1]<<" rolls"<<endl;
            cout<<"The Probability of "<<i<<" is: "<<1.0*d->result[i-1]/d->index<<endl<<endl;
        }
    }




int main (int argc, char *argv[]) {

    ::srand(time(0));
    int n=*argv[1]-'0';
    struct dice *d = new struct dice();

    initialise(d);

    for(int i=0; i<n; i++){
        newroll(d);
    }

    calculateresults(d);
    showresults(d);


    return 0;
}
