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

    int xmax = 1000;
    int ymax = 800;

    Simple_window win {Point{100,100}, xmax, ymax, "Drill2"};

    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    //background
    
    Rectangle rectBg {Point{0,0},x_size,y_size};
    rectBg.set_fill_color(Color::white);
    rectBg.set_color(Color::invisible);

    win.attach(rectBg);

    //grid
    
    Lines grid;
    for (int x = x_grid; x <= x_size; x+=x_grid)
    	grid.add(Point{x,0},Point{x,y_size});
    for (int y = y_grid; y <= y_size; y+=y_grid)
    	grid.add(Point{0,y},Point{x_size,y});

    win.attach(grid);
	
    //diagonal
    Rectangle rect0 {Point{0,0},100,100};
    Rectangle rect1 {Point{100,100},100,100};
    Rectangle rect2 {Point{200,200},100,100};
    Rectangle rect3 {Point{300,300},100,100};
    Rectangle rect4 {Point{400,400},100,100};
    Rectangle rect5 {Point{500,500},100,100};
    Rectangle rect6 {Point{600,600},100,100};
    Rectangle rect7 {Point{700,700},100,100};

    rect0.set_fill_color(Color::red);
    rect1.set_fill_color(Color::red);
    rect2.set_fill_color(Color::red);
    rect3.set_fill_color(Color::red);
    rect4.set_fill_color(Color::red);
    rect5.set_fill_color(Color::red);
    rect6.set_fill_color(Color::red);
    rect7.set_fill_color(Color::red);

    rect0.set_color(Color::invisible);
    rect1.set_color(Color::invisible);
    rect2.set_color(Color::invisible);
    rect3.set_color(Color::invisible);
    rect4.set_color(Color::invisible);
    rect5.set_color(Color::invisible);
    rect6.set_color(Color::invisible);
    rect7.set_color(Color::invisible);

    win.attach(rect0);
    win.attach(rect1);
    win.attach(rect2);
    win.attach(rect3);
    win.attach(rect4);
    win.attach(rect5);
    win.attach(rect6);
    win.attach(rect7);

    //images
    //200x200
    Image two {Point{600,0},"200x200.gif"};
    Image two1 {Point{0,600},"200x200.gif"};

    win.attach(two);
    win.attach(two1);

	//Right
	int x_cord0 = 100;
	int y_cord0 = 0;

	//Left
	int x_cord1 = 0;
	int y_cord1 = 100;
	bool increasing=true;
	//100x100
	while(true)
	{
		Image one {Point{x_cord0,y_cord0},"100x100.gif"};
		Image one1 {Point{x_cord1,y_cord1},"100x100.gif"};

		win.attach(one);
		win.attach(one1);

		if (increasing==true)
		{
			if (x_cord0==500)
			{
				increasing=false;
				y_cord0+=100;
				x_cord1+=100;
			}
			x_cord0+=100;
			y_cord1+=100;
		}

		if (increasing==false)
		{
			if (x_cord0==200)
			{
				increasing=true;
				y_cord0-=100;
				x_cord1-=100;
			}
			x_cord0-=100;
			y_cord1-=100;
		}
		win.wait_for_button();
	}
}