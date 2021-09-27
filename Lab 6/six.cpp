#include <bits/stdc++.h>
#include <FL/Fl.H>        // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
using namespace std;

void callback(void *)
{
    //collision();
    cout<<"test"<<endl;
    Fl::repeat_timeout(1.0, callback); // retrigger timeout
}

class MyCircle;

class GameManager{
    public:
    MyCircle *list[100], *bonus[10];
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
    
    void collision(){
        // for (int i = 0; i < 100; i++)
        //     {
        //         int xcoor=obj.list[i]->getx();
        //         int ycoor= obj.list[i]->gety();

        //         double distance = sqrt(1.0 * ((x - xcoor) * (x - xcoor) + (y - ycoor) * (y - ycoor)));

        //         if(distance < 40){
        //             cout<<"here";
        //             exit(0);
        //         }
        //     }
    }

    virtual int handle(int e)
    {
        if (e == FL_PUSH)
        {
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
            collision();


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

    MyCircle *c= new MyCircle(30, 30, 30, 255, 0, 0, 1, b1);


    for (int i = 0; i < 100; i++)
    {
        b1.list[i] = new MyCircle(rand() % 1170 + 30, rand() % 770 + 30, 30, 0, 255, 0, 2, b1);
    }

    for (int i = 0; i < 10; i++)
    {
        b1.bonus[i] = new MyCircle(rand() % 1100 + 100, rand() % 700 + 100, 30, 0, 0, 255, 3, b1);
    }

    window->color(FL_WHITE);
    window->end();
    window->show();






    Fl::add_timeout(1.0, callback);
    return Fl::run(); // the process waits from here on for events, goes into a loop. Terminated by cross button
}
