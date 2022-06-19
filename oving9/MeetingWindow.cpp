#include "std_lib_facilities.h"
#include "MeetingWindow.h"
#include "AnimationWindow.h"
#include "Meeting.h"

MeetingWindow::MeetingWindow(int x, int y, int w, int h, const string& title) 
: AnimationWindow(x, y, w, h, title), 
quitBtn(30, 30, btnW, btnH, "Quit"), 
personName(w/3, h/2, fieldW, fieldH, "Name"), 
personEmail(w/3, h/2-2*fieldH, fieldW, fieldH, "Email"),
personNewBtn(w/3, h/2+2*fieldH, fieldW, fieldH, "New Person") {
    add(quitBtn); 
    add(personNewBtn); 
    add(personName); 
    add(personEmail); 
    quitBtn.callback(cb_new_person, this); 
    quitBtn.callback(cb_quit, this); 
}

void MeetingWindow::cb_quit(Fl_Widget*, void* pw) {
    static_cast<MeetingWindow*>(pw)->hide();
}

void MeetingWindow::cb_new_person(Fl_Widget*, void* pw) {
    static_cast<MeetingWindow*>(pw)->newPerson();
    
}

void MeetingWindow::newPerson() {
    people.emplace_back(new Person{personEmail.value(), personName.value()});
    personEmail.value();
    personName.value();
}

