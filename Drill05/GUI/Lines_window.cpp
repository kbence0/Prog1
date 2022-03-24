#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},

    //--
    color_menu{Point{x_max()-150*2,50},150,40,Menu::vertical,"color"},
    menu_button{Point{x_max()-150*2,50}, 150, 40, "color menu", [](Address, Address pw) {reference_to<Lines_window>(pw).menu_pressed();}},

    //4.
    line_menu{Point{x_max()-150,50},150,40,Menu::vertical,"Ln style"},
    line_menu_button{Point{x_max()-150,50}, 150, 40, "line menu", [](Address, Address pw) {reference_to<Lines_window>(pw).line_menu_pressed();}}
    //--
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    //--
    xy_out.put("no point");
    color_menu.attach(new Button{Point{0,0},0,0,"red",[](Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",[](Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}});
    color_menu.attach(new Button{Point{0,0},0,0,"black",[](Address, Address pw) {reference_to<Lines_window>(pw).black_pressed();}});

    attach(color_menu);
    color_menu.hide();
    attach(menu_button);

    //4.
    line_menu.attach(new Button{Point{0,0},0,0,"solid",[](Address, Address pw) {reference_to<Lines_window>(pw).solid_pressed();}});
    line_menu. attach(new Button{Point{0,0},0,0,"dash",[](Address, Address pw) {reference_to<Lines_window>(pw).dash_pressed();}});
    line_menu. attach(new Button{Point{0,0},0,0,"dot",[](Address, Address pw) {reference_to<Lines_window>(pw).dot_pressed();}});
    attach(line_menu);
    line_menu.hide();
    attach(line_menu_button);
    //--
    attach(lines);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}