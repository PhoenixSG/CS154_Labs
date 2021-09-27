/*  Author- Shashwat Garg, 200050130
    Date- 5 Apr, 2021

    Developing the 15 number puzzle, using FLTK and GUI interface
*/

#include <bits/stdc++.h>
#include <FL/Fl.H>		  // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> //to include buttons in the window

using namespace std;

char *charstar_from_int(int v)
{ //convert int to char*
	if (v == 16)
	{
		char *buffer = new char[1];
		buffer = (char *)" ";
		return buffer;
	}
	char *buffer = new char[sizeof(int)];
	sprintf(buffer, "%d", v);
	return buffer;
}

class GameManager;

class MyButton : public Fl_Button
{

	GameManager *gameptr;
	int x_index, y_index;
	int name;

public:
	MyButton(GameManager *ptr, int x_coor, int y_coor, int x_location, int y_location, int height, int width);
	int handle(int e);
	void set_name(int input);
	int return_name() { return name; }
	int return_x() { return x_index; }
	int return_y() { return y_index; }
};

class GameManager
{
	MyButton *buttons[4][4]; //The 16 buttons
	int empty_x, empty_y;	 //The numbers of empty button

public:
	GameManager();
	int make_the_move(int, int, int);
	int check_ans();
	void shuffle();
};

MyButton::MyButton(GameManager *ptr, int x_coor, int y_coor, int x_location, int y_location, int height, int width) : Fl_Button(x_coor, y_coor, width, height)
{
	label(charstar_from_int(4 * y_location + x_location + 1));
	gameptr = ptr;
	x_index = x_location;
	y_index = y_location;
}

void MyButton::set_name(int input)
{
	name = input;
	label(charstar_from_int(name));
}

int MyButton::handle(int e)
{
	if (e == FL_PUSH)
	{
		cout << "Button Clicked, Coordinates- " << x_index + 1 << ", " << y_index + 1 << endl;

		gameptr->make_the_move(x_index, y_index, name);
	}
	return 1;
}

GameManager::GameManager()
{

	for (int i = 0; i < 4; i++)
	{ //Initialising the grid
		for (int j = 0; j < 4; j++)
		{
			buttons[i][j] = new MyButton(this, 100 * i + 150, 100 * j + 100, i, j, 100, 100);
			buttons[i][j]->color(FL_GREEN);
		}
	}
	shuffle();
}

int GameManager::check_ans()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (buttons[i][j]->return_name() != i + j * 4 + 1)
				return 0;
		}

	cout << "Congrats! You solved the puzzle\n";
	exit(0);

	return 1;
}

int GameManager::make_the_move(int x_index, int y_index, int name)
{

	if (((empty_x == x_index) && (abs(y_index - empty_y) == 1)) || (empty_y == y_index) && (abs(x_index - empty_x) == 1))
	{
		buttons[x_index][y_index]->color(FL_GRAY);
		buttons[empty_x][empty_y]->color(FL_GREEN);
		buttons[x_index][y_index]->label((char *)" ");
		buttons[x_index][y_index]->set_name(16);
		buttons[empty_x][empty_y]->set_name(name);
		buttons[empty_x][empty_y]->label(charstar_from_int(name));
		empty_x = x_index;
		empty_y = y_index;

		check_ans();
		return 1; //Swap made
	}
	return 0; //Swap not made
}

void GameManager::shuffle()
{
	srand(time(0));

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{

			buttons[i][j]->set_name(4 * i + j + 1);
			buttons[i][j]->label(charstar_from_int(4 * i + j + 1));
		}
	}

	buttons[3][3]->label(" ");
	empty_x = 3;
	empty_y = 3;
	buttons[3][3]->color(FL_GRAY);

	for (int i = 0; i < 500; i++)
	{
		MyButton *temp = buttons[rand() % 4][rand() % 4];
		make_the_move(temp->return_x(), temp->return_y(), temp->return_name());
	}
}

int main(int argc, char *argv[])
{
	Fl_Window *window;

	window = new Fl_Window(700, 600, "The 15 Puzzle"); // outer window

	window->color(FL_WHITE);

	GameManager game;

	window->end();	//Saying that window and components have been finished. Nothing more can be added now
	window->show(); //Show all the components

	int s = Fl::run();	 // the process waits from here on for events, goes into a loop. Terminated by cross button
	cout << "Exiting\n"; //No effect, since control does not reach here. Program ends after return is executed.
	return s;
}
