#pragma once
#include "Campus.h"
#include "Person.h"
#include <vector>
#include <memory>

class Meeting {
    private:
        int day;
        int startTime;
        int endTime;
        Campus location;
        std::string subject;
        std::shared_ptr<Person> leader;
        std::vector<std::shared_ptr<Person>> participants;
    public:
        //CONSTRUCTOR
        Meeting(int dayDay, int startT, int endT, Campus loc, std::string sub, std::shared_ptr<Person> lead);
        
        //GET FUNCTIONS
        int get_day();
        int get_startTime();
        int get_endTime();
        Campus get_location();
        std::string get_subject();
        std::shared_ptr<Person> get_leader();
        void add_participants(std::shared_ptr<Person> p);
        std::vector<std::string> getParticipants();
        std::vector<std::shared_ptr<Person>> findPotentionCoDriving(Meeting& m);
};