//CS  154
//Author: Prof. R. K. Joshi
//Exercise: Fix the errors in this program and make it work
//when the board is solved, flag a message
//add a randomize button to shuffle pieces into a valid initial problem position

#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>

using namespace std;

char *int_to_chararray(int v)
{
	char *s = new char[sizeof(int)];
	sprintf(s, "%d", v);
	return s;
};

class GameManager;
class MyButton;

class MyButton : public Fl_Button
{
	//Fl_Button *button;
	GameManager *parent;
	int x_index, y_index;

public:
	int name;
	MyButton(GameManager *b, int xp, int yp, int x, int y, int pw, int ph);
	int handle(int);
	int return_name() { return name; }
};

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
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (pieces[x][y]->return_name() != x + y * 4 + 1)
				return 0;
		}

	switch (fl_choice("You won!!", "New Game", "Exit", "Party!!"))
	{
	case 0:
		randomize();
		break;
	case 1:
		exit(0);
		break;
	case 2:
		break;
	case 3:
		break;
	}

	return 1;
}

MyButton::MyButton(GameManager *b, int xp, int yp, int x, int y, int pw, int ph) : Fl_Button(x, y, pw, ph, ((name = xp + yp * 4 + 1) == 16) ? (char *)" " : int_to_chararray(name))
{
	;
	parent = b;
	x_index = xp;
	y_index = yp;
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
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			pieces[x][y] = new MyButton(this, x, y, x0 + x * pw, y0 + y * ph, pw, ph);

	empty_x = empty_y = 3; // current empty position

	newGame = new MyButton(this, 3, 4, x0 + 3 * pw, y0 + 4 * ph, pw, ph);
	newGame->label("NEWGAME!!");
}
int GameManager::move(int x, int y, int mylabl)
{

	cout << "move request " << x << " " << y << " " << mylabl << " " << empty_x << " " << empty_y << " " << endl;
	if (((empty_x == x) && (abs(y - empty_y) == 1)) || (empty_y == y) && (abs(x - empty_x) == 1))
	{ // valid, swap the pieces
		pieces[x][y]->label((char *)"");
		pieces[x][y]->name = 16;
		pieces[empty_x][empty_y]->name = mylabl;
		pieces[empty_x][empty_y]->label(int_to_chararray(mylabl));
		empty_x = x;
		empty_y = y;
		if (check_ans())
		{
			cout << "Solved\n";
		}
		return 1; //success
	}
	return 0;
}

void GameManager::randomize()
{

	//srand(time(0));
	bool visited[16];
	for (int i = 0; i < 16; i++)
		visited[i] = false;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			int i = (int)random() % 16 + 1;
			if (!visited[i - 1])
			{
				pieces[x][y]->name = i;
				visited[i - 1] = true;
				if (i != 16)
					pieces[x][y]->label(int_to_chararray(i));

				else
				{
					pieces[x][y]->label("");
					empty_x = x;
					empty_y = y;
				}
			}
			else
			{
				y--;
				continue;
			}
		}
	}
}

int main(int argc, char *argv[])
{

	int X = 400, Y = 400;		// height width of actual puzzle
	int bx = 150, by = 50;		// border margins from x and y axis
	int pw = X / 4, ph = X / 4; // height width of pieces

	int emptyx = 3, emptyy = 3;
	Fl_Button *buttons[4][4];

	Fl_Window *w = new Fl_Window(X + 2 * by, Y + 2 * bx); // board is 25% larger
	w->label("CS 757 15 Puzzle Lecture 2");

	GameManager b(by, bx, pw, ph);

	w->end();
	w->show(argc, argv);
	return Fl::run();
}
