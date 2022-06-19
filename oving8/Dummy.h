#pragma once
#include <iostream>

class Dummy {
    public:
        int *num;

        Dummy() {
            num = new int{0};
        }

        Dummy(const Dummy& other);

        
        Dummy &operator=(Dummy rhs);

        void dummyTest();

        int get() const { return *num; }

        ~Dummy() {
            delete num;
        }
};


