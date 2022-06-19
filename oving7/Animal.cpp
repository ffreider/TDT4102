#include "std_lib_facilities.h"
#include "Animal.h"

Animal::Animal(string namer, int ager) {
    this->name = namer;
    this->age = ager;
}

string Animal::toString() {
    return "Animal: " + name + ", " + to_string(age); 
}