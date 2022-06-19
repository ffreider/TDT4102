#pragma once
#include "AnimationWindow.h"
#include "Person.h"

class MeetingWindow : AnimationWindow {
    private:
        int x, y, w, h;
        string title;
        static constexpr int pad = 10;
        static constexpr int btnW = 50;
        static constexpr int btnH = 30;
        static constexpr int fieldW = 200;
        static constexpr int fieldH = 30;
        static constexpr int fieldPad = 10;
        Fl_Button quitBtn;
        Fl_Button personNewBtn;
        Fl_Input personName;
        Fl_Input personEmail;
        vector<shared_ptr<Person>> people;
    public:
        MeetingWindow(int x, int y, int w, int h, const string& title);
        static void cb_quit(Fl_Widget*, void* pw);
        static void cb_new_person(Fl_Widget*, void* pw);
        void newPerson();
};