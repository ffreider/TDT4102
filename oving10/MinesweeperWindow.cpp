#include "MinesweeperWindow.h"


MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines}
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->callback(cb_click, this);
			add(tiles.back().get()); 
		}
	}

	// Legger til miner paa tilfeldige posisjoner
	for (int i = 0; i < mines; i++) {
		tiles[rand()%tiles.size()]->set_isMine(true);
	}

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	if (at(xy)->getState() == Cell::closed) {
		at(xy)->open();
	} else {return;}
	if (at(xy)->get_isMine()) {
		// win.begin();
		Fl_Output *output = new Fl_Output(0, 0, 500, 40, "Hello");
		output->value("Minesweeper FLTK Creaters: Shahzain Ali");
		cout << "boo,";
		FL.run();
	} else {
		if (countMines(adjacentPoints(xy)) > 0) {
			at(xy)->setAdjMines(countMines(adjacentPoints(xy)));
		} else {
			for (int i = 0; i < static_cast<int>(adjacentPoints(xy).size()); i++) {
				if (at(adjacentPoints(xy)[i])->getState() == Cell::open) {
					return;
				}
				for (int i = 0; i < static_cast<int>(adjacentPoints(xy).size()); i++) {
					openTile(adjacentPoints(xy)[i]);
				}
			}
		}
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	if (at(xy)->getState() == Cell::flagged || at(xy)->getState() == Cell::closed) {
		at(xy)->flag();
	}
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::click()
{
	Point xy{Fl::event_x(), Fl::event_y()};

	MouseButton mb = static_cast<MouseButton>(Fl::event_button());

	if (!inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		openTile(xy);
		break;
	case MouseButton::right:
		flagTile(xy);
		break;
	}
}

int MinesweeperWindow::countMines(vector<Point> coords) const{
	int mines = 0;
	for (int i = 0; i < static_cast<int>(coords.size()); i++) {
		if (at(coords[i])->get_isMine()) {
			mines++;
		}
	}
	return mines;
}