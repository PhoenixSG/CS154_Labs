/* Author: R.K. Joshi, IIT Bombay */
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <cstdlib>
class MyProgram : public Fl_Widget
{
    int D;
    int a, b, c, d;

public:
    MyProgram(int x1, int y1, int x2, int y2, char *label = 0) : Fl_Widget(x1, y1, x2, y2, label)
    {
        a = x1;
        b = y1;
        c = x2;
        d = y2;
    }
    void setdepth(int d) { D = d; };
    void draw() { drawsq(a, b, c, d, D); }

    void drawsq(int x1, int y1, int x2, int y2, int depth)
    {
        if (depth <= 0)
            return;
        fl_color((int)random() % 256);
        fl_line(x1, y1, x2, y1);
        fl_line(x1, y1, x1, y2);
        fl_line(x1, y2, x2, y2);
        fl_line(x2, y1, x2, y2);
        drawsq(x1 + 10, y1 + 10, x2 - 10, y2 - 10, depth - 1);
    }
};
int main(int argc, char *argv[])
{
    Fl_Window *w = new Fl_Window(800, 800, "Squares");
    w->color(56);
    MyProgram p(0, 0, 800, 800);
    if (argc == 1)
        p.setdepth(7);
    else
        p.setdepth(atoi(argv[1]));
    w->resizable(p);
    w->show();
    return (Fl::run());
}
