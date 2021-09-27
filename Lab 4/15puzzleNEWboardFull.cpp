/*  Author- Shashwat Garg, 200050130
    Date- 5 Apr, 2021

    CS154 Lab 4- Developing the 15 number puzzle, using FLTK and C++, using OOP and GUI based programming
*/

#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>


using namespace std;

char *int_to_chararray(int input){

	char *buffer = new char[sizeof(int)];
	sprintf(buffer, "%d", input);
	return buffer;
}

class GameManager;

class MyButton : public Fl_Button
{
	GameManager *parent;
	int x_index, y_index;
	int name;

public:
	
	MyButton(GameManager *ptr, int x_position, int y_position, int x_coor, int y_coor, int pw, int ph);
	int handle(int);
	void set_name(int input);
	int return_name() { return name; }
};

void MyButton::set_name(int input)
{
	name = input;
	label(int_to_chararray(name));
}





class GameManager
{
	MyButton *pieces[4][4];
	MyButton *newGame;

	int empty_x, empty_y; // position of empty piece
public:
	GameManager(int, int, int, int);
	int move(int, int, int);
	void randomize();
	int check_ans();
};

int GameManager::check_ans()
{
	for (int x_coor = 0; x_coor < 4; x_coor++)
		for (int y_coor = 0; y_coor < 4; y_coor++)
		{
			if (pieces[x_coor][y_coor]->return_name() != x_coor + y_coor * 4 + 1)
				return 0;
		}

		cout<<"You Won!!\n";
		exit(0);

	return 1;
}

MyButton::MyButton(GameManager *ptr, int x_position, int y_position, int x_coor, int y_coor, int pw, int ph) : Fl_Button(x_coor, y_coor, pw, ph)
{
	;
	parent = ptr;
	x_index = x_position;
	y_index = y_position;
}
int MyButton::handle(int event)
{
	if (event == FL_PUSH)
	{
		cout << "mouse pushed on " << x_index << " " << y_index << endl;

		if (name == 20)
		{
			parent->randomize();
		}
		else
			parent->move(x_index, y_index, name);
	}
	return 1;
};

GameManager::GameManager(int x0, int y0, int pw, int ph)
{
	for (int x_coor = 0; x_coor < 4; x_coor++)
		for (int y_coor = 0; y_coor < 4; y_coor++)
			pieces[x_coor][y_coor] = new MyButton(this, x_coor, y_coor, x0 + x_coor * pw, y0 + y_coor * ph, pw, ph);

	empty_x = empty_y = 3; // current empty position

	newGame = new MyButton(this, 3, 4, x0 + 3 * pw, y0 + 4 * ph, pw, ph);
	newGame->label("NEWGAME!!");
}
int GameManager::move(int x_coor, int y_coor, int mylabl)
{

	if (((empty_x == x_coor) && (abs(y_coor - empty_y) == 1)) || (empty_y == y_coor) && (abs(x_coor - empty_x) == 1))
	{
		pieces[x_coor][y_coor]->label((char *)"");
		pieces[x_coor][y_coor]->set_name(16);
		pieces[empty_x][empty_y]->set_name(mylabl);
		pieces[empty_x][empty_y]->label(int_to_chararray(mylabl));
		empty_x = x_coor;
		empty_y = y_coor;
		cout << "Move made!\n";
		if (check_ans())
		{
			cout << "Solved\n";
		}
		
		return 1;
	}
	return 0;
}

void GameManager::randomize()
{

	//srand(time(0));
	bool visited[16];
	for (int i = 0; i < 16; i++)
		visited[i] = false;

	for (int x_coor = 0; x_coor < 4; x_coor++)
	{
		for (int y_coor = 0; y_coor < 4; y_coor++)
		{
			int i = (int)random() % 16 + 1;
			if (!visited[i - 1])
			{
				pieces[x_coor][y_coor]->set_name(i);
				visited[i - 1] = true;
				if (i != 16)
					pieces[x_coor][y_coor]->label(int_to_chararray(i));

				else
				{
					pieces[x_coor][y_coor]->label("");
					empty_x = x_coor;
					empty_y = y_coor;
				}
			}
			else
			{
				y_coor--;
				continue;
			}
		}
	}
}

int main(int argc, char *argv[])
{

	int X = 400, Y = 400;		// height width of actual puzzle
	int bx = 150, by = 50;		// border margins from x_coor and y_coor axis
	int pw = X / 4, ph = X / 4; // height width of pieces

	int emptyx = 3, emptyy = 3;
	Fl_Button *buttons[4][4];

	Fl_Window *w = new Fl_Window(X + 2 * by, Y + 2 * bx); // board is 25% larger
	w->label("CS 757 15 Puzzle Lecture 2");

	GameManager ptr(by, bx, pw, ph);

	w->end();
	w->show(argc, argv);
	return Fl::run();
}
