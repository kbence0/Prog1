/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double slope(double x) {return x/2;}

double square(double x) { return x*x; }

double sloping_cos(double x) {
    	return cos(x)+slope(x);
    }

int main()
{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 600;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    Simple_window win {Point{100,100}, xmax, ymax, "Function graphs"};

    Point orig {x_orig, y_orig};
    
    int r_min = -10;
    int r_max = 11;

    int n_points = 400;


    int x_scale = 20;
    int y_scale = 20;

    //4.
    int xlength = 400;
    int ylength = 400;
    
    Axis x {Axis::x,Point{100,y_orig},
    	xlength,xlength/x_scale,"1==20 pixels"};
    	
    Axis y {Axis::y,Point{x_orig,ylength+100},
    	xlength,xlength/x_scale,"1==20 pixels"};
    	
    x.set_color(Color::red);
    y.set_color(Color::red);
    
    x.label.move(-160,0);
    x.notches.set_color(Color::dark_red);
    y.label.move(-40,5);

    //Functions
    Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
    Function s2 {slope,r_min,r_max,orig,n_points,x_scale,25};
    Function s3 {square,r_min,r_max,orig,n_points,25,25};
    Function s4 {cos,r_min,r_max,orig,400,30,30};
    s4.set_color(Color::blue);
    Function s5 {sloping_cos,r_min,r_max,orig,400,30,30};
    win.attach(s);
    win.attach(s2);
    win.attach(s3);
    win.attach(s4);
    win.attach(s5);
    
    //Attaches
    win.attach(x);
    win.attach(y);

    win.wait_for_button();
}