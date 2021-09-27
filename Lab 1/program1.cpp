#include <bits/stdc++.h>
using namespace std;

//OOP approach


long long int factorial(int n){
    if(n==0) return 1;

    return factorial(n-1)*n;
}


class dice{
private:
    int roll_stats[100];
    int index;
    int result[6];

public:
    dice(){
        for(int i=0; i<100; i++){
            roll_stats[i]=0;
        }
        index=0;
        for(int i=0; i<6; i++){
            result[i]=0;
        }
    }

    int randomgen(){
        return rand()%6+1;
    }


    void newroll(){
        roll_stats[index]=randomgen();
        index++;
    }

    void calculateresults(){
        for(int i=0; i<index; i++){
            result[roll_stats[i]-1]++;
        }
    }

    void showresults(){
        calculateresults();
        for(int i=1; i<=6; i++){
            cout<<i<<": "<<result[i-1]<<" rolls"<<endl;
            cout<<"The Probability of "<<i<<" is: "<<1.0*result[i-1]/index<<endl<<endl;
        }
    }

    long long int no_of_ways(){
        long long int ans=1;

        for(int i=0; i<6; i++){
            ans*=factorial(result[i]);
        }
        return ans;
    }

};


int main (int argc, char *argv[]) {

    ::srand(time(0));
    int n=*argv[1]-'0';
    dice d1;

    for(int i=0; i<n; i++){
        d1.newroll();
    }

    d1.showresults();

//    long double ans=(1.0*factorial(n)/d1.no_of_ways())/pow(6,n);
//    cout<<"The Probability of such a distribution is: "<<ans;

    return 0;
}
