#include <math.h>

#include "Chassis.h"
#include "../Robotmap.h"
#include "../commands/HolonomicDrive.h"

Chassis::Chassis(): Subsystem("Chassis") {
	driveMotorA = new Victor (MOTOR_A_PWM);
    driveMotorB = new Victor (MOTOR_B_PWM);
    driveMotorC = new Victor (MOTOR_C_PWM);
}

Chassis::~Chassis() {
	delete driveMotorA;
    delete driveMotorB;
    delete driveMotorC;
}

void Chassis::InitDefaultCommand() {
	SetDefaultCommand(new HolonomicDrive());
}

void Chassis::drive(double vX, double vY, double vZ, double throttle) {
	double vMotor[3];  
    
    vMotor[0] = (vX*0) - vY -vZ;
    vMotor[1] = -(vX*sqrt(3) /2.0 + vY/2.0 -vZ);
    vMotor[2] = -(-vX*sqrt(3) /2.0 + vY/2.0 -vZ);
    
    double vmax = 1.0; // sets maximum value to 1
	for(int i = 0; i < 3; ++i){
		if(abs(vMotor[i]) >vmax ) {
			vmax =abs (vMotor [i]); // sets the absolute motor value to vmax 
            //if it is greater than 1 
		}
	}
    
    // takes the votor values and scales them according to what vmax * throttle is 
    for (int i = 0; i < 3; ++i){
		vMotor[i] = vMotor[i]/vmax*throttle;
	}
    driveMotorA->Set(vMotor[0]);
    driveMotorB->Set(-vMotor[1]);
    driveMotorC->Set(-vMotor[2]);
    
    SmartDashboard::PutNumber("Motor A", vMotor[0]);
    SmartDashboard::PutNumber("Motor B", vMotor[1]);
    SmartDashboard::PutNumber("Motor C", vMotor[2]);
}

void Chassis::liveWindow() {
	
}
