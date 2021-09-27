/*
Author- Shashwat Garg, 200050130.

Making a game using fltk and demonstrating fltk graphics.
*/

#include <bits/stdc++.h>

using namespace std;


class GameManager{
    private:
    int x[100];
    int y[100];
    
    public:

    GameManager(){
        for(int i=0; i<10; i++){
            x[i]=0;
            y[i]=0;
        }
    }

    void setx(int i){
        x[i]=(rand() % 1100 + 30);
    }
    void sety(int i){
        y[i]=(rand() % 700 + 30);
    }
    int getx(int i){return x[i];}
    int gety(int i){return y[i];}

    void collision(int xcoor, int ycoor){
        for (int i = 0; i < 10; i++)
            {
                cout<<x[i]<<endl<<y[i]<<endl<<endl;
                int xdiff=xcoor-x[i];
                int ydiff=ycoor-y[i];
                
                double distance = sqrt(xdiff*xdiff+ydiff*ydiff);
                cout<<distance<<endl<<endl;
                if(distance < 30){
                    cout<<"Foul"<<endl;
                    exit(0);
                }
            }
    }
};



int main(int argc, char *argv[])
{

    srand(time(0));

    GameManager b1;
    for (int i = 0; i < 100; i++)
    {
        b1.setx(i);
        b1.sety(i);
        cout<<b1.getx(i)<<endl<<b1.gety(i)<<endl<<endl;
    }
    b1.collision(100,100);


    return 0;
}
