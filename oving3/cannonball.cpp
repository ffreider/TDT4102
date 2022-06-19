#include "cannonball.h"
#include "std_lib_facilities.h"
#include <math.h>

double acclY() {
    return -9.81;
}

double velY(double initVelocityY, double time) {
    return initVelocityY + acclY()*time;
}

double posX(double initPosition, double initVelocityY, double time) {
    return initPosition + initVelocityY*time;
}

double posY(double initPosition, double initVelocityY, double time) {
    return initPosition + initVelocityY*time + (acclY()*time*time)/2;
}
void printTime(double sec) {
    if (sec <= 60) {
        cout << sec << " sekunder\n";
    } else if (sec <= 3600) {
        cout << sec/60 << " minutter og " << static_cast<int>(sec)%60 << " sekunder\n";
    } else {
        int hours = sec/3600;
        int minutes = (sec-(hours*3600))/60;
        double seconds = sec-minutes*60-hours*3600; 
        cout << hours << " time(r), " << minutes << " minutt(er) og " << seconds << " sekund(er)\n";
    }
}
double flightTime(double initVelocityY) {
    return (-2*initVelocityY)/acclY();
}

double getUserInputTheta() {
    double a = 0;
    cout << "Velg vinkel: ";
    cin >> a;
    return a;
}

double getUserInputAbsVelocity() {
    double a = 0;
    cout << "absolutt fart: ";
    cin >> a;
    return a;
}

double pi = 3.14159265358979323846;


double degToRad(double deg) {
    return deg * pi / 180;
}

double getVelocityX(double theta, double absVelocity) {
    return absVelocity * cos(theta);
}

double getVelocityY(double theta, double absVelocity) {
    return  absVelocity * sin(theta);
}
vector<double> getVelocityVector(double theta, double absVelocity) {
    vector<double> vec;
    vec.push_back(getVelocityX(degToRad(theta), absVelocity));
    vec.push_back(getVelocityY(degToRad(theta), absVelocity));
    return vec;
}

double getDistanceTraveled(double velocityX, double velocityY) {
    return (posX(0, velocityX, flightTime(velocityY)));
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

bool checkIfDistanceToTargetIsCorrect() {
		double error = targetPractice(100,0,0);
		if(error == 5) return true;
        else return false;
}