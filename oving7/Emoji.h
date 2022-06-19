#pragma once
#include "AnimationWindow.h"
#include "Graph.h"


// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.

class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face: public Emoji {
    protected:
        Point centre;
        int radius;
    public:
        Face(Point c, int r);
        virtual void draw(AnimationWindow&) = 0;
};

class EmptyFace: public Face {
    public:    
        EmptyFace(Point c, int r)
            : Face(c, r) {}
        void draw(AnimationWindow& win) override;     
}; 

class Smilefjes: public EmptyFace {
    public:    
        Smilefjes(Point c, int r): EmptyFace(c, r) {};
        void draw(AnimationWindow& win);
};

class SadFace: public EmptyFace {
    public:    
        SadFace(Point c, int r): EmptyFace(c, r) {};
        void draw(AnimationWindow& win);
};

class AngryFace: public SadFace {
    public: 
        AngryFace(Point c, int r): SadFace(c, r) {};
        void draw(AnimationWindow& win);
};

class WinkingFace: public Smilefjes {
    public:
        WinkingFace(Point c, int r): Smilefjes(c, r) {};
        void draw(AnimationWindow& win);
};

class SuprisedFace: public EmptyFace {
    public:
        SuprisedFace(Point c, int r): EmptyFace(c, r) {};
        void draw(AnimationWindow& win);
};