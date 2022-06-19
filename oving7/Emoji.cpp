#include "Emoji.h"


Face::Face(Point c, int r) {
    this->radius = r;
    this->centre = c;
}
void Face::draw(AnimationWindow&) {
    AnimationWindow win;
    win.draw_circle(centre, radius, Color::yellow);
}

void EmptyFace::draw(AnimationWindow& win) {
    Face::draw(win);
    win.draw_circle(centre, radius, Color::yellow);
    win.draw_circle({centre.x-radius/2, radius/2}, radius/3, Color::white);
    win.draw_circle({centre.x+radius/2, radius/2}, radius/3, Color::white);
    win.draw_circle({centre.x-radius/2, radius/2}, radius/6, Color::black);
    win.draw_circle({centre.x+radius/2, radius/2}, radius/6, Color::black);
}
void Smilefjes::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_arc({centre.x, centre.y}, radius, radius, 190, 350);
}

void SadFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_arc({centre.x, centre.y+centre.y/2}, radius, radius, 10, 170);
}

void AngryFace::draw(AnimationWindow& win) {
    SadFace::draw(win);
    win.draw_line({centre.x-radius/2-radius/3, centre.y-radius/2-radius/3}, {centre.x-radius/2+radius/3, radius/2-radius/4}, Color::black);
    win.draw_line({centre.x+radius/2-radius/3, centre.y-radius/2-radius/4}, {centre.x+radius/2+radius/3, radius/2-radius/3}, Color::black);
}

void WinkingFace::draw(AnimationWindow& win) {
    Smilefjes::draw(win);
    win.draw_circle({centre.x+radius/2, radius/2}, radius/3, Color::yellow);
    win.draw_arc({centre.x+radius/2, radius-radius/2}, radius/2, radius/4, 60, 120);
    win.draw_arc({centre.x+radius/2, radius-radius/2}, radius/2, radius/2, 60, 120);
}

void SuprisedFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_arc({centre.x, centre.y+radius/6}, radius-radius/3, radius/2, 0, 360);
}
