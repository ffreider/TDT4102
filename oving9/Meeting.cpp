#include "Meeting.h"
#include "Person.h"
#include <memory>


//CONSTRUCTOR
Meeting::Meeting(int dayDay, int startT, int endT, Campus loc, std::string sub, const std::shared_ptr<Person> lead) {
    day = dayDay;
    startTime = startT;
    endTime = endT;
    location = loc;
    subject = sub;
    leader = lead; // Help
    participants.push_back(lead);
}

// GET FUNCTIONS
int Meeting::get_day() {
return day;
}
int Meeting::get_startTime() {
    return startTime;
}
int Meeting::get_endTime() {
    return endTime;
}
Campus Meeting::get_location() {
    return location;
}
std::string Meeting::get_subject() {
    return subject;
}
std::shared_ptr<Person> Meeting::get_leader() {
    return leader;
}

void Meeting::add_participants(std::shared_ptr<Person> p) {
    participants.push_back(p);
}

std::vector<std::string> Meeting::getParticipants() {
    std::vector<std::string> names;
    for (int i = 0; i < static_cast<int>(participants.size()); i++) {
        names.push_back(participants[i]->get_name()); // Hvordan dereferencer jeg her?
    }
    return names;
}



std::vector<std::shared_ptr<Person>> Meeting::findPotentionCoDriving(Meeting &m) {
    std::vector<std::shared_ptr<Person>> coDrivers;
        
    if (m.get_location() == location && m.get_day() == day && abs(m.get_startTime()-startTime) < 1 && abs(m.get_endTime()-endTime) < 1) {
        for (std::shared_ptr<Person> p : m.participants) {
            if (p->hasAvailableSeats()) {
                coDrivers.push_back(p);
            }
        }
    }

    return coDrivers;
}