#pragma once

class Car {
    private:
        int freeSeats;
    public:
        // KONSTRUKTØR
        Car(int free);

        bool hasFreeSeats() const;
        void reserveFreeSeat();
        int get_freeSeats();
};