#include <iostream>
#include <string>
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> //to include buttons in the window
#include <FL/Fl_Box.H> 

using namespace std;

char* charstar_from_int(int v){

	char* buffer=new char[sizeof(int)];
	sprintf(buffer,"%d", v);
	return buffer;
}

int main(int argc, char *argv[]) {
    	Fl_Window *window;

window = new Fl_Window (1000,800,"Changed Size and Label"); // outer window

		Fl_Button *buttons[4][4];

		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				buttons[i][j]=new Fl_Button(100*(i+1),100*(j+1),100,100,charstar_from_int(4*j+i+1));
			}
		}


    	window->end();	//Saying that window and components have been finished. Nothing more can be added now
    	
		window->show();	//Show all the components



    	int s=Fl::run();  	// the process waits from here on for events, goes into a loop. Terminated by cross button
							//Seems like this is a static function
							
							/*As long as any windows are displayed this calls Fl::wait() repeatedly.
							When all the windows are closed it returns zero
							A normal program will end main() with return Fl::run();
							*/

		cout<<"Exiting\n";  //No effect, since control does not reach here. Program ends after return is executed.

		return s;
}


