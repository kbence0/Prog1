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
    color_menu{Point{x_max()-80,50},150,40,Menu::vertical,"color"},
    menu_button{Point{x_max()-80,50}, 150, 40, "color menu", cb_menu},

    //4.
    line_menu{Point{x_max()-150,50},150,40,Menu::vertical,"Ln style"},
    line_menu_button{Point{x_max()-150,50}, 150, 40, "line menu", cb_menu}
    //--
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    //--
    xy_out.put("no point");
    color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);

    //4.
    line_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
    line_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});
    line_menu.attach(new Button{Point{0,0},0,0,"dot",cb_dot});
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