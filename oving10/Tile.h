#pragma once
#include "GUI.h"


// De forskjellige tilstandene en Tile kan vaere i
enum class Cell { closed, open, flagged }; 

class Tile : public Fl_Button
{
	bool isMine = false;
	Cell state = Cell::closed;
	
public:
	void set_label(string s) { this->copy_label(s.c_str());}
	void set_label_color(Color c) {this->labelcolor(c.as_int());}
	Tile(Point pos, int size) 
		 :Fl_Button(pos.x, pos.y, size, size, "") {};
	void setAdjMines(int n);

	void open();
	void flag();
	void set_isMine(bool b);
	bool get_isMine();

	Cell getState() const { return state; };

};
