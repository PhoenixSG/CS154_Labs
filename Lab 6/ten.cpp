/*
Author- Shashwat Garg, 200050130.

Improving a game using fltk and demonstrating fltk graphics.
*/

#include <bits/stdc++.h>
#include <FL/Fl.H>        // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Button.H> //to include buttons in the window

using namespace std;

class GameManager
{
private:
    int first[100];
    int second[100];

public:
    GameManager()
    {
        for (int i = 0; i < 100; i++)
        {
            first[i] = 0;
            second[i] = 0;
        }
    }

    void setx(int i)
    {
        first[i] = (rand() % 1100 + 30);
    }
    void sety(int i)
    {
        second[i] = (rand() % 700 + 30);
    }
    int getx(int i) { return first[i]; }
    int gety(int i) { return second[i]; }

    void collision(int xcoor, int ycoor)
    {
        for (int i = 0; i < 100; i++)
        {

            int xdiff = xcoor - first[i];
            int ydiff = ycoor - second[i];

            double distance = sqrt(xdiff * xdiff + ydiff * ydiff);

            if (distance < 30)
            {
                cout << "Foul" << endl;
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
    MyCircle(int x, int y, int w, int r, int g, int b, int t, GameManager &o) : Shape(x, y, w, w)
    {
        shapecolor = fl_rgb_color(r, g, b);
        type = t;
        obj = o;
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

    int getx() { return x; }
    int gety() { return y; }

    void move(int i);
};

void MyCircle::move(int i)
{
    if (i==1)
    {
        wipe();
        refresh(0, -10);
    }
    else if (i==2)
    {
        wipe();
        refresh(-10, 0);
    }
    else if (i==3)
    {
        wipe();
        refresh(0, 10);
    }
    else if (i==4)
    {
        wipe();
        refresh(10, 0);
    }

    obj.collision(x, y);

    if (x <= 10)
    {
        wipe();
        x = 10;
        refresh(0, 0);
    }
    if (y <= 10)
    {
        wipe();
        y = 10;
        refresh(0, 0);
    }
    if (x >= 1170)
    {
        wipe();
        x = 1170;
        refresh(0, 0);
    }
    if (y >= 770)
    {
        wipe();
        y = 770;
        refresh(0, 0);
    }

    if (x == 1170 && y == 770)
    {
        cout << "You Won!" << endl;
        exit(0);
    }
}




class MyButton : public Fl_Button
{
    MyCircle *player;
    int type;

public:
    MyButton(char* name, int t, int x_location, int y_location, int height, int width, MyCircle *p);
    int handle(int e);
};

MyButton::MyButton(char* name, int t, int x_location, int y_location, int height, int width, MyCircle *p) : Fl_Button(x_location, y_location, width, height)
{
    label(name);
    type = t;
    player = p;
}
int MyButton::handle(int e)
{
    if (e == FL_PUSH)
    {
        player->move(type);
    }
    if (e == FL_KEYBOARD)
        {
            if ((char)Fl::event_key() == 'w')
            {
            player->move(1);
            }
            else if ((char)Fl::event_key() == 'a')
            {
            player->move(2);
            }
            else if ((char)Fl::event_key() == 's')
            {
            player->move(3);
            }
            else if ((char)Fl::event_key() == 'd')
            {
            player->move(4);
            }
        }
        return 1;
    
};

int main(int argc, char *argv[])
{

    Fl_Window *window;
    window = new Fl_Window(1200, 800, "My Improved Game"); // outer window

    srand(time(0));

    GameManager g1;

    

    for (int i = 0; i < 100; i++)
    {
        g1.setx(i);
        g1.sety(i);
        new MyCircle(g1.getx(i), g1.gety(i), 30, 0, 255, 0, 2, g1);
    }

    MyCircle *c = new MyCircle(30, 30, 30, 255, 0, 0, 1, g1);

    MyButton up((char*)"Up", 1, 1100, 0,  50, 50, c);
    MyButton left((char*)"Left", 2, 1050, 50,  50, 50, c);
    MyButton down((char*)"Down", 3, 1100, 50,  50, 50, c);
    MyButton right((char*)"Right", 4, 1150, 50,  50, 50, c);


    window->color(FL_WHITE);
    window->end();
    window->show();

    //Fl::add_timeout(1.0, callback);
    return Fl::run(); // the process waits from here on for events, goes into a loop. Terminated by cross button
}
