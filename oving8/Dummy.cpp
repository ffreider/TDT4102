#include "Dummy.h"
#include <iostream>
#include <utility>

void Dummy::dummyTest() {
    Dummy a;
    std::cout << "line 6" << std::endl;
    *a.num = 4; // a == 4
    std::cout << "line 8" << std::endl;
    Dummy b{a}; // b får samme adresse som a
    std::cout << "line 10" << std::endl;
    Dummy c;    
    c = a;      // c får samme adresse som a
    std::cout << "a: " << *a.num << '\n'; // Skriver ut a
    std::cout << "b: " << *b.num << '\n'; // Skriver ut a
    std::cout << "c: " << *c.num << '\n'; // Skriver ut a
    *b.num = 3; // a, b og c == 3
    *c.num = 5; // a, b og c == 5
    std::cout << "a: " << *a.num << '\n'; // Alle peker på c sin verdi
    std::cout << "b: " << *b.num << '\n';
    std::cout << "c: " << *c.num << '\n'; 
}

Dummy::Dummy(const Dummy &other) : num{ nullptr } {
    // std::cout << "Kopiert!" << std::endl; // DEBUG
    this->num = new int{};
    *num = other.get(); 
}

Dummy &Dummy::operator=(Dummy rhs) {
    std::swap(num, rhs.num); 
    return *this;
}


