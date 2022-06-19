#include "Person.h"
#include "Car.h"

#include <string>
#include <memory>
#include <iostream>



std::string Person::get_name() {
    return name;
}

std::string Person::get_email() {
    return email;
}
void Person::set_email(std::string new_email) {
    email = new_email;
}

bool Person::hasAvailableSeats() {
    Car temp = *Person::car;
    if (temp.hasFreeSeats()) {
        return true;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "Name: " << p.name << std::endl << "Email: " << p.email << std::endl;
    if (p.car != nullptr) {
        Car seatCount = *p.car;
        std::string seats;
        if (seatCount.hasFreeSeats()) {
            seats = "atleast one seat available.";
        } else {
            seats = "no extra seats.";
        }
        std::string hasCar;
        if (p.car != nullptr) {
            hasCar = "";
        } else {
            hasCar = " not ";
        }
        os << "This person does " << hasCar << "have a car." << std::endl << "They have " << seats << std::endl << std::endl;  
    }
    return os;
}