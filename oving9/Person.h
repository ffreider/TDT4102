#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Car.h"

class Person {
    private:
        std::string name;
        std::string email;   
        std::unique_ptr<Car> car;
    public:
        Person(std::string namer, std::string emailer, std::unique_ptr<Car> carer  = nullptr) : name{namer}, email{emailer}, car(move(carer)) {}; // forskjell på ( {})
        std::string get_name();
        std::string get_email();
        void set_email(std::string new_email);
        bool hasAvailableSeats();   
        friend std::ostream& operator<<(std::ostream& os, const Person& p);
};