#include "std_lib_facilities.h"
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "AnimationWindow.h"
#include "Emoji.h"


void testAnimal() {
    // Animal animal("dyrete dyr", 104);
    Dog doggy("Luna", 4);
	Cat kitty("Fillip", 10);
	// cout << animal.toString() << endl;
	cout << doggy.toString() << endl;
	cout << kitty.toString() << endl; 

	// vector<Animal> v;
	// // v.emplace_back(animal);
	// v.emplace_back(doggy);
	// v.emplace_back(kitty));
	// for (int i = 0; i < int(v.size()); i++) {
	// 	cout << v[i].toString() << endl;
	// }
}

constexpr int xmax = 1000;
constexpr int ymax = 600;
// constexpr int emojiRadius = 50;

int main() {
	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};
	AngryFace test(Point{200, 200}, 200);
	test.draw(win);
	win.wait_for_close();
}
