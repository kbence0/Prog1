/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 1280;
    int ymax = 720;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -10;
    int rmax = 10;
    
    int n_points = 400;

    //window position to place it in the middle of the screen
    int centerx = xmax-(1920/2);
    int centery = ymax-(1080/2);

    Simple_window win {Point{centerx,centery}, xmax, ymax, "My window"};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 40;
	int ylength = ymax - 40;

	int xscale = 30, yscale = 30;

	Function s (one, rmin-11, rmax+11, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); },
						rmin-11, rmax+11, origo, n_points, xscale, yscale);

	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{20, ylength + 20}, ylength, ylength/yscale, "y"};

	Rectangle r {Point{xmax-200,ymax-100}, 200, 100};

	r.set_fill_color(Color::blue);
	r.set_style(Line_style(Line_style::dash, 4));

	Text t {Point{x_orig-90,y_orig+315}, "Hello graphics!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii {Point{xmax-400,ymax-600}, "badge.jpg"};

	Circle c {Point{20,y_orig}, 100};

	Ellipse e {Point{x_orig,ymax-50}, 100, 50};
	e.set_fill_color(Color::red);

	win.attach(e);
	win.attach(ii);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);
	win.attach(x);
	win.attach(y);

    win.wait_for_button();

}
