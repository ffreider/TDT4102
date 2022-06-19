#include "std_lib_facilities.h"
#include "Dog.h"


string Dog::toString() {
    return "Dog: " + name + ", " + to_string(age); 
}