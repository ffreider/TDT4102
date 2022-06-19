#include "Tile.h"

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const map<int, Color> minesToColor{{1, Color::blue},
								   {2, Color::red},
								   {3, Color::dark_green},
								   {4, Color::dark_magenta},
								   {5, Color::dark_blue},
								   {6, Color::dark_cyan},
								   {7, Color::dark_red},
								   {8, Color::dark_yellow}};

// For aa sette Tilelabel i henhold til state
const map<Cell, string> cellToSymbol{{Cell::closed, ""},
									 {Cell::open, ""},
									 {Cell::flagged, "@<"}};

void Tile::open()
{
		if (state == Cell::closed) {
			this->set();// Setter en button som trykket paa, tilsvarer aapnet rute
			state = Cell::open;
			if (isMine == true) {
				this->set_label("X");
				this->set_label_color(2);
			}
		}
}

void Tile::flag() {
	if (state == Cell::flagged) {
		state = Cell::closed;
		this->set_label("");
	} else if (state != Cell::flagged) {
		state = Cell::flagged;
		this->set_label(cellToSymbol.at(state));
		this->set_label_color(1);
	}
}

void Tile::set_isMine(bool b) {
	isMine = b;
}
bool Tile::get_isMine() {
	return isMine;
}

void Tile::setAdjMines(int n) {
	set_label(to_string(n));
	set_label_color(minesToColor.at(n));
}
