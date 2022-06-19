#pragma once
#include "std_lib_facilities.h"

double acclY();
double velY(double initVelocityY, double time);
double velX(double initVelocityY, double time);
double posX(double initPosition, double initVelocityY, double time);
double posY(double initPosition, double initVelocityY, double time);                                                                                                         
void printTime(double sec);
double flightTime(double initVelocityY);
double getUserInputTheta();
double getUserInputAbsVelocity();
double degToRad(double deg);
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);
vector<double> getVelocityVector(double theta, double absVelocity);
double targetPractice(double distanceToTarget, double velocityX, double velocityY);
bool checkIfDistanceToTargetIsCorrect();