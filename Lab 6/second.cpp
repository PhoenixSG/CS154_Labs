#include <bits/stdc++.h>
#include <FL/Fl.H>        // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
using namespace std;

class Shape : public Fl_Widget
{
protected:
    int x, y, w, h;
    Fl_Color shapecolor= fl_rgb_color(255,0,0);

public:
    Shape(int x, int y, int w, int h) : Fl_Widget(x, y, w, h)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }
    virtual void wipe() = 0;
    virtual void refresh(int dx, int dy) = 0;

};

class MyCircle : public Shape
{
public:
    MyCircle(int x, int y, int w) : Shape(x, y, w, w) {}
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
        virtual int handle(int e)
    {
        if (e == FL_PUSH)
        {
            
        }
        if (e == FL_KEYBOARD)
        {
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
        }
        return 1;
    };
};







int main(int argc, char *argv[])
{
    Fl_Window *window;
    window = new Fl_Window(1200, 800, "DEMO"); // outer window

        
        
        
        
        
        
        
        new MyCircle(600, 600, 30);










    window->color(FL_WHITE);
    window->end();
    window->show();
    int s = Fl::run(); // the process waits from here on for events, goes into a loop. Terminated by cross button
    cout << "Exiting\n";
    return s;
}
