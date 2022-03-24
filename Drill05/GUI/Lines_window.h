#include "GUI.h"
#include "Graph.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

	bool wait_for_button();

private:
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	//--
	Menu color_menu;
	Button menu_button;
	//3.
	Menu line_menu;
	Button line_menu_button;

	void change(Color c){lines.set_color(c);}
	//4.
	void changel(Line_style l){lines.set_style(l);}
	
	void hide_menu() {color_menu.hide(); menu_button.show();}
	
	//4.
	void hide_line_menu() {line_menu.hide(); line_menu_button.show();}

	void red_pressed() {change(Color::red); hide_menu();}
	void blue_pressed() {change(Color::blue); hide_menu();}
	void black_pressed() {change(Color::black); hide_menu();}
	void menu_pressed() {menu_button.hide(); color_menu.show();}

	
	
	//4.
	void solid_pressed() {changel(Line_style::solid); hide_line_menu();}
	void dash_pressed() {changel(Line_style::dash); hide_line_menu();}
	void dot_pressed() {changel(Line_style::dot); hide_line_menu();}
	void line_menu_pressed() {line_menu_button.hide(); line_menu.show();}

	//----------
	void next();
	void quit();
	//----------
	
	static void cb_red(Address,Address);
	static void cb_blue(Address,Address);
	static void cb_black(Address,Address);
	static void cb_menu(Address,Address);
	static void cb_next(Address,Address);
	static void cb_quit(Address,Address);

	//4.
	static void cb_solid(Address,Address);
	static void cb_dash(Address,Address);
	static void cb_dot(Address,Address);
	//--
	
};