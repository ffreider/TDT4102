#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"
#include "cannonball_viz.h"
#define LOG(x) std::cout << x << std::endl


int main() {
	// playTargetPractice();

	int angle = getUserInputTheta();
	int speed = getUserInputAbsVelocity();
	cannonBallViz(500, 1000, getVelocityX(angle, speed), getVelocityY(angle, speed), 100);
	srand(unsigned(time(nullptr)));
	return 0;
}

