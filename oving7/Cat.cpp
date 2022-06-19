#include "std_lib_facilities.h"
#include "Cat.h"

string Cat::toString() {
    return "Cat: " + name + ", " + to_string(age); 
}