#include <math.h>

#include "Chassis.h"
#include "../Robotmap.h"

Chassis::Chassis(): Subsystem("Chassis") {
	driveMotorA = new Victor (MOTOR_A_PWM);
    driveMotorB = new Victor (MOTOR_B_PWM);
    driveMotorC = new Victor (MOTOR_C_PWM);
}

Chassis::~Chassis() {
	
}

void Chassis::InitDefaultCommand() {
	
}

void Chassis::drive(double vX, double vY, double vZ, double throttle) {
	
}

void Chassis::liveWindow() {
	
}
