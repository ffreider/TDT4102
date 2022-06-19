#include "utilities.h"
#include "std_lib_facilities.h"
#include "cannonball.h"
 
int randomWithLimits(int upper, int lower) {
    int num = rand() % lower + upper;
    return num;
}

void playTargetPractice() {
    // Plasser blinken
    int targetPosX = randomWithLimits(100, 1000);
    int x = 1;
    int y = 0;
    while (x > 0) {
        double angle =  getUserInputTheta();
        double speed = getUserInputAbsVelocity();
        if (targetPractice(targetPosX,  getVelocityX(angle, speed),  getVelocityY(angle, speed)) < 5 && targetPractice(targetPosX,  getVelocityX(angle, speed),  getVelocityY(angle, speed)) > 0) {
            cout << "Du traff!!";
            x = 0;
        } else {
            cout << "Bommet med " << targetPractice(targetPosX,  getVelocityX(angle, speed),  getVelocityY(angle, speed)) << " meter\n";
            printTime(flightTime(getVelocityY(angle, speed)));
            y++;
        }
        if (y == 9) {
            cout << "Game over.... :(";
            x = 0;
        }
    }
}