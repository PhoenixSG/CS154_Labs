/*
Author- Shashwat Garg, 200050130.

Improving the structure of the game made using fltk and demonstrating fltk graphics.
*/

#include <bits/stdc++.h>  //handles iostream and math functions in this program
#include <FL/Fl.H>        //needed in every fltk program
#include <FL/Fl_Window.H> //needed to use the Fl_Window class
#include <FL/fl_draw.H>   //needed to draw the circles
#include <FL/Fl_Button.H> //to include buttons in the window

using namespace std; //for cout, to display fouls and final win messages

class GameManager //Handles collision between main coin and barriers. Keeps information about barrier locations
{
private:
    int first[100];
    int second[100];

public:
    GameManager()
    {
        for (int i = 0; i < 100; i++) //Set random porition  of the barriers
        {
            first[i] = (rand() % 1100 + 30);
            ;
            second[i] = (rand() % 700 + 30);
        }
    }

    int getx(int i) { return first[i]; }  //Return the coordinates
    int gety(int i) { return second[i]; } //Passed onto barrier constructors

    void collision(int xcoor, int ycoor) //Check for incorrect move. Start again if illegal move
    {
        for (int i = 0; i < 100; i++)
        {
            int xdiff = xcoor - first[i];
            int ydiff = ycoor - second[i];

            double distance = sqrt(xdiff * xdiff + ydiff * ydiff);

            if (distance < 30)
            {
                cout << "Foul! You touched the barriers! Try Again." << endl;
                exit(0);
            }
        }
    }
};

class Shape : public Fl_Widget //Parent class for all shapes. Inheriting predefined widget class.
{
protected:
    int x, y, w, h; //Holds location, size and color of shape
    Fl_Color shapecolor;

public:
    Shape(int x, int y, int w, int h, int r, int g, int b) : Fl_Widget(x, y, w, h) //Initialisation of variables
    {
        shapecolor = fl_rgb_color(r, g, b);
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }
};

class MyCircle : public Shape
{

private:
    int type;        //holds information about type of shape, whether barrier or player
    GameManager obj; //For checking for legal moves

public:
    MyCircle(int x, int y, int w, int r, int g, int b, int t, GameManager &o) : Shape(x, y, w, w, r, g, b)
    {
        type = t;
        obj = o;
    }

    virtual void draw() //Makes the shape
    {
        fl_color(shapecolor);
        fl_pie(x, y, w, h, 0, 360);
    }

    virtual void wipe() //Removes the shape
    {
        fl_color(FL_WHITE);
        fl_pie(x, y, w, h, 0, 360);
    }

    virtual void refresh(int dx, int dy) //Redraws the relocated the shape
    {
        x = x + dx;
        y = y + dy;
        resize(x, y, w, h);
        fl_color(shapecolor);
        fl_pie(x, y, w, h, 0, 360);
    }

    void move(int i);   //Called by handle() function  &&  Calls the collision function
};

void MyCircle::move(int i)
{
    if (i == 1)         //Movement of player circle, up, down, left or right
    {
        wipe();
        refresh(0, -10);
    }
    else if (i == 2)
    {
        wipe();
        refresh(-10, 0);
    }
    else if (i == 3)
    {
        wipe();
        refresh(0, 10);
    }
    else if (i == 4)
    {
        wipe();
        refresh(10, 0);
    }

    obj.collision(x, y);        //calls for collision testing

    if (x <= 10)                //Maintains player coin inside playing field
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

    if (x == 1170 && y == 770)  //winning check. Print Win message if coin reaches bottom right corner.
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
    MyButton(char *name, int t, int x_location, int y_location, int height, int width, MyCircle *p);
    int handle(int e);
};

MyButton::MyButton(char *name, int t, int x_location, int y_location, int height, int width, MyCircle *p) : Fl_Button(x_location, y_location, width, height)
{
    label(name);            //Initialises the name, color and other properties of the button
    color(FL_BLUE);
    type = t;
    player = p;
}

int MyButton::handle(int e)
{
    if (e == FL_PUSH)       //mouse control control
    {
        player->move(type);
    }

    if (e == FL_KEYBOARD)   //keyboard keys control
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

    srand(time(0));     //random order different everytime

    GameManager g1;

    for (int i = 0; i < 100; i++)
    {
        new MyCircle(g1.getx(i), g1.gety(i), 30, 0, 255, 0, 2, g1);
    }

    MyCircle *c = new MyCircle(30, 30, 30, 255, 0, 0, 1, g1);

    MyButton up((char *)"Up", 1, 1100, 0, 50, 50, c);
    MyButton left((char *)"Left", 2, 1050, 50, 50, 50, c);
    MyButton down((char *)"Down", 3, 1100, 50, 50, 50, c);
    MyButton right((char *)"Right", 4, 1150, 50, 50, 50, c);

    window->color(FL_WHITE);
    window->end();      // finishing creation of all items
    window->show();     // display all the items on the screen

    return Fl::run();   // the process waits from here on for events, goes into a loop. Terminated by cross button
}
