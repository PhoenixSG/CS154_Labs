#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
void callback(void*) {
  printf("TICK\n");
  Fl::repeat_timeout(1.0, callback);    // retrigger timeout
}
int main() {
  Fl_Window win(100,100);
  win.show();
  Fl::add_timeout(1.0, callback);       // set up first timeout
  return Fl::run();
}