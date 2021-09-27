/*
Author- Shashwat Garg, 200050130.

Making a game using fltk and demonstrating fltk graphics.
*/

#include <bits/stdc++.h>
#include <FL/Fl.H>        // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
using namespace std;

// void callback(void *)
// {
//     //collision();
//     cout<<"test"<<endl;
//     Fl::repeat_timeout(1.0, callback); // retrigger timeout
// }



class GameManager{
    private:
     int first[100];
     int second[100];
    
    public:

    GameManager(){
        for(int i=0; i<100; i++){
            first[i]=0;
            second[i]=0;
        }
    }

    void setx(int i){
        first[i]=(rand() % 1100 + 30);
        cout<<first[i]<<endl;
    }
    void sety(int i){
        second[i]=(rand() % 700 + 30);
        cout<<second[i]<<endl;
    }
    int getx(int i){return first[i];}
    int gety(int i){return second[i];}

    void collision(int xcoor, int ycoor){
        for (int i = 0; i < 100; i++)
            {
                cout<<first[i]<<endl<<second[i]<<endl<<endl;
                int xdiff=xcoor-first[i];
                int ydiff=ycoor-second[i];
                cout<<xdiff<<endl<<ydiff<<endl<<endl;
                
                double distance = sqrt(xdiff*xdiff+ydiff*ydiff);
                //cout<<distance<<endl<<endl;
                if(distance < 30){
                    cout<<"Foul"<<endl;
                    exit(0);
                }
            }
    }
};

class Shape : public Fl_Widget
{
protected:
    int x, y, w, h;
    Fl_Color shapecolor;

public:
    Shape(int x, int y, int w, int h) : Fl_Widget(x, y, w, h)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }
};

class MyCircle : public Shape
{

private:
    int type;
    GameManager obj;

public:
    MyCircle(int x, int y, int w, int r, int g, int b, int t, GameManager o) : Shape(x, y, w, w)
    {
        shapecolor = fl_rgb_color(r, g, b);
        type = t;
        obj=o;
    }

    virtual void draw()
    {
        fl_color(shapecolor);
        fl_pie(x, y, w, h, 0, 360);
    }

    virtual void wipe()
    {
        fl_color(FL_WHITE);
        fl_pie(x, y, w, h, 0, 360);
    }

    virtual void refresh(int dx, int dy)
    {
        x = x + dx;
        y = y + dy;
        resize(x, y, w, h);
        fl_color(shapecolor);
        fl_pie(x, y, w, h, 0, 360);
    }

    int getx(){return x;}
    int gety(){return y;}
    


    virtual int handle(int e)
    {
        if (e == FL_PUSH && type==1)
        {
            wipe();
            refresh(10,10);
             obj.collision(x,y);
        }
        if (e == FL_KEYBOARD && type == 1)
        {

            if ((char)Fl::event_key() == ' ')
            {
                ;
            }

            if ((char)Fl::event_key() == 'w')
            {
                wipe();
                refresh(0, -10);
            }
            else if ((char)Fl::event_key() == 'a')
            {
                wipe();
                refresh(-10, 0);
            }
            else if ((char)Fl::event_key() == 's')
            {
                wipe();
                refresh(0, 10);
            }
            else if ((char)Fl::event_key() == 'd')
            {
                wipe();
                refresh(10, 0);
            }

              obj.collision(x,y);
    

            if(x<=10){wipe(); x=10; refresh(0,0);}
            if(y<=10){wipe(); y=10; refresh(0,0);}
            if(x>=1170){wipe(); x=1170; refresh(0,0);}
            if(y>=770){wipe(); y=770; refresh(0,0);}

            if(x==1170 && y==770){
                cout<<"You Won!"<<endl;
                exit(0);
            }

            

        }

        return 1;
    };
};

int main(int argc, char *argv[])
{

    Fl_Window *window;
    window = new Fl_Window(1200, 800, "My Game"); // outer window

    srand(time(0));

    GameManager b1;

    // for(int i=0; i<10; i++){
    //     b1.setx(i);
    //     b1.sety(i);
    // }

   

    
    for (int i = 0; i < 100; i++)
    {
        b1.setx(i);
        b1.sety(i);
        new MyCircle(b1.getx(i),b1.gety(i) , 30, 0, 255, 0, 2, b1);
        cout<<b1.getx(i)<<endl<<b1.gety(i)<<endl<<endl;
    }

    MyCircle *c= new MyCircle(30, 30, 30, 255, 0, 0, 1, b1);

    // for (int i = 0; i < 10; i++)
    // {
    //     b1.bonus[i] = new MyCircle(rand() % 1100 + 100, rand() % 700 + 100, 30, 0, 0, 255, 3, b1);
    // }

    window->color(FL_WHITE);
    window->end();
    window->show();

    //Fl::add_timeout(1.0, callback);
    return Fl::run(); // the process waits from here on for events, goes into a loop. Terminated by cross button
}
