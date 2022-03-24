/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp Lines_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Lines_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 600;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    //window position to place it in the middle of the screen
    int centerx = (1920/2)-x_orig;
    int centery = (1080/2)-y_orig;

    Lines_window win {Point{centerx,centery},xmax,ymax,"Lines"};


    return gui_main();

}
