#include <iostream>
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> //to include buttons in the window
#include <FL/Fl_Box.H> 

using namespace std;

int main(int argc, char *argv[]) {
    	Fl_Window *window;

window = new Fl_Window (1000,800,"Changed Size and Label"); // outer window

		Fl_Button *button1 = new Fl_Button(300,100,10,300,"Button1");//(top-left_x-coor, top-left_y-coor, width, height, label)
        
		window->end();	//Saying that window has been finished

		Fl_Button *button2 = new Fl_Button(300,300,100,100,"Button2");

		//Here only button 1 is displayed, since after end() function, no new objects are created.
		//Objects are displayed when show is called and only objects declared before end() and show() are displayed.
    	
    	window->show();	//Show all the components



    	int s=Fl::run();  // the process waits from here on for events, goes into a loop. Terminated by cross button
		
		cout<<"Exiting\n";  //No effect, since control does not reach here. Program ends after return is executed.

		return s;
}


