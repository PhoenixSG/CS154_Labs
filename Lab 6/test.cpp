/*  Author- Shashwat Garg, 200050130
    Date- 5 Apr, 2021

    Developing the 15 number puzzle, using FLTK and GUI interface
*/

#include <bits/stdc++.h>
#include <FL/Fl.H>          // needed in every fltk program
#include <FL/Fl_Window.H>   // needed to use the Fl_Window class
#include <FL/Fl_Button.H>   // to include buttons in the window
#include <Fl/fl_draw.H>     // to draw the shapes
#include <Fl/Fl_Box.H>      // to draw the boxes

using namespace std;

char *charstar_from_int(int v)  //convert int to char*
{
    char *buffer = new char[sizeof(int)];
    sprintf(buffer, "%d", v);
    return buffer;
}

class shape: public Fl_Widget{

    private:
    int x;
    int y, w, h;

    public:

    void draw(){
        fl_box
    }

};





int main(int argc, char *argv[])
{
    Fl_Window *window;

    window = new Fl_Window(700, 600, "The 15 Puzzle"); // outer window

    window->color(FL_WHITE);

    shape s1;



    window->end();  //Saying that window and components have been finished. Nothing more can be added now
    window->show(); //Show all the components

    int s = Fl::run(); // the process waits from here on for events, goes into a loop. Terminated by cross button
    cout << "Exiting\n";
    return s;
}
