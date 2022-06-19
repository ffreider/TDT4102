#pragma once
#include "std_lib_facilities.h"
#include "Animal.h"

class Dog: public Animal {
    public:
        using Animal::Animal;
        string toString();
        ~Dog() {};
};