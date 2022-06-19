#include "Car.h"

// KONSTRUKTØR
Car::Car(int free) {
    freeSeats = free;
}


bool Car::hasFreeSeats() const{
    if (freeSeats > 0) {
        return true;
    } else {
        return false;
    }
}

void Car::reserveFreeSeat() {
    freeSeats--;
}

