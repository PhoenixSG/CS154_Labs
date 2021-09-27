/* Author: R.K. Joshi, IIT Bombay */
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <cstdlib>
class MyProgram : public Fl_Widget {
int w, h, D;
public:
     MyProgram (int winx, int winy, int s1, int s2, char *label=0) : 
		Fl_Widget (winx, winy, s1,s2,label) { w = s1; h=s2; }
     void setdepth (int d) {D = d;};
     void draw(){ drawtri (0, h, w, h, w/2, 0, D);}
void drawtri (int x1, int y1, int x2, int y2, int x3, int y3, int depth) {
	if (depth<=0) return;	
	fl_color ((int) random()%256);
/*      	fl_line(x1,y1,x2,y2);
       	fl_line(x2,y2,x3,y3);
	fl_line(x3,y3,x1,y1);
       	fl_line((x3+x1)/2,(y3+y1)/2,(x2+x3)/2,(y3+y2)/2);
       	fl_line((x3+x1)/2,(y3+y1)/2,(x2+x1)/2,(y1+y2)/2);
       	fl_line((x3+x2)/2,(y3+y2)/2,(x2+x1)/2,(y1+y2)/2); */
	fl_polygon((x3+x1)/2,(y3+y1)/2,(x2+x3)/2,(y3+y2)/2,(x1+x2)/2,(y1+y2)/2);
       	drawtri((x3+x1)/2,(y3+y1)/2,(x2+x3)/2,(y3+y2)/2, x3,y3, depth-1);
 }
};
int main(int argc, char *argv[]) {
  int recursionDepth;
    if (argc!=2) recursionDepth = 6; else recursionDepth=atoi(argv[1]);
    Fl_Window w(800,800,"cs152: sierpinski triangle");
    w.color(56);
    MyProgram p(0,0,800,800);
    p.setdepth (recursionDepth);
    w.resizable (p);
    w.show();
    return(Fl::run());
}


