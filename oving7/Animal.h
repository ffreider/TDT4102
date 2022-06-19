#pragma once
#include "std_lib_facilities.h"

class Animal {
    protected:
        string name;
        int age;
    public:
        Animal(string name, int age);
        virtual string toString()=0;
        virtual ~Animal() {};
};

