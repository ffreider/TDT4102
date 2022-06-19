#include "std_lib_facilities.h"
#include "Car.h"
#include "Person.h"
#include "Campus.h"
#include "Meeting.h"
#include "AnimationWindow.h"
#include "MeetingWindow.h"


int b = 2;
int *ptr = &b;



std::ostream& operator<<(std::ostream &out, Campus c) {
	switch(c) {
		case Campus::Trondheim:
			out << "Trondheim";
			return out;
		case Campus::Ålesund:
			out << "Ålesund";
			return out;
		case Campus::Gjøvik:
			out << "Gjøvik";
			return out;
		default:
			out << "Ikke gyldig";
			return out;
	}
}


std::ostream &operator<<(std::ostream &c, Meeting &m) {
    c << "Subject: " << m.get_subject() << std::endl;
    c << "Location: " << m.get_location() << std::endl;
    c << "Start time: " << m.get_startTime() << std::endl;
    c << "End time: " << m.get_endTime() << std::endl;
    c << "Leader: " << m.getParticipants()[0] << std::endl;
    c << "Participants: "; 
    for (int i = 1; i < static_cast<int>(m.getParticipants().size())-1; i++) {
        c << m.getParticipants()[i] << "    " << std::endl;
    }
    return c;
}


int main()
{
	// Car one(0);
	// Car two(1);
	// Person testPerson1("Freider", "freider.floan@gmail.com", make_unique<Car>(one));
	// Person testPerson2("Theia", "theia.floan@gmail.com", make_unique<Car>(two));
	// cout << testPerson1;
	// cout << testPerson2;


	// cout << Campus::Ålesund;
	// Meeting m{10, 1, 3, Campus{1}, "Hello", std::make_shared<Person>(Person{"Freider", "Fløan", make_unique<Car>(Car{2})}) };
	// Meeting n{10, 1, 3, Campus{1}, "Hello", std::make_shared<Person>(Person{"Bob", "Fløan", make_unique<Car>(Car{2})}) };
	// // cout << m;
	// std::vector<shared_ptr<Person>> meeting = n.findPotentionCoDriving(m);
	// for (shared_ptr<Person> p : meeting) {
	// 	cout << p->get_name() << endl;
	// }

	// Fl_Button quit{10, 10, 10, 10, "Quit"};
	MeetingWindow w(50, 50, 500, 500, "Test");
	gui_main();

	return 0;
}
