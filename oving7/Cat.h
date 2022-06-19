#pragma once
#include "std_lib_facilities.h"
#include "Animal.h"

class Cat: public Animal {
    public:
        using Animal::Animal;
        string toString();
        ~Cat() {};
};