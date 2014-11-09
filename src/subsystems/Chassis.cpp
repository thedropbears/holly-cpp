#include <math.h>

#include "Chassis.h"
#include "../Robotmap.h"
#include "../commands/HolonomicDrive.h"
#include <CommandBase.h>

Chassis::Chassis(): Subsystem("Chassis") {
	driveMotorA = new Victor (MOTOR_A_PWM);
    driveMotorB = new Victor (MOTOR_B_PWM);
    driveMotorC = new Victor (MOTOR_C_PWM);
    
    
    correction = new GyroCorrection();
    gyro_pid = new PIDController(-0.005 ,0,0,CommandBase::dropboneimu,correction);
    gyro_pid->SetInputRange(-2*PI, 2*PI);
    gyro_pid->Enable();
    
    SetHeading = 0.0;
    
    weBePimpin = false;
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
    
    
    if(weBePimpin){
		double heading = CommandBase::dropboneimu->getYawAngle()*3.14159/180.0;
		double vXpimp = vX*cos(heading)+vY*sin(heading);
		double vYpimp = -vX*sin(heading)+vY*cos(heading);
		vX = vXpimp;
		vY = vYpimp;
	}
	
	double ax = log(JOYSTICK_X_EXPONENTIAL+1);
	double ay = log(JOYSTICK_Y_EXPONENTIAL+1);
	double az = log(JOYSTICK_Z_EXPONENTIAL+1);

	
	if (vX > 0) {
		vX = (exp(ax*vX)-1)/JOYSTICK_X_EXPONENTIAL;
	} else {
		vX = -(exp(ax*-vX)-1)/JOYSTICK_X_EXPONENTIAL; 
		}
		
	if (vY > 0) {
		vY =(exp(ay*vY)-1)/JOYSTICK_Y_EXPONENTIAL;
	} else {
		vY = -(exp(ay*-vY)-1)/JOYSTICK_Y_EXPONENTIAL; 
	}
		
	if (vZ > 0) {
		vZ = (exp(az*vZ)-1)/JOYSTICK_Z_EXPONENTIAL;
	} else {
		vZ = -(exp(az*-vZ)-1)/JOYSTICK_Z_EXPONENTIAL; 
	}

    	if (weBePimpin){
	if (vZ != 0 || (abs(CommandBase::dropboneimu->getYawRate()) > 2 && !gyro_pid->IsEnabled())) {
        
        SetHeading = CommandBase::dropboneimu->getYawAngle();
        gyro_pid->Reset();
        gyro_pid->SetSetpoint(SetHeading);
        gyro_pid->Enable();
        correction->correction = 0;
    } else {
        vZ = correction->correction;
    }
    }
    
    vMotor[0] = (vX*0) - vY -vZ;
    vMotor[1] = -(vX + vY/2.0 -vZ);
    vMotor[2] = -(-vX + vY/2.0 -vZ);
    
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
    SmartDashboard::PutNumber("gyro Heading (deg)", CommandBase::dropboneimu->getYawAngle());
    SmartDashboard::PutNumber("gyro SetPoint (deg)", SetHeading);
    SmartDashboard::PutNumber("control loop output", correction->correction);
    SmartDashboard::PutBoolean("are we Pimpin", weBePimpin);
}


void Chassis::gyroReset() {
	CommandBase::dropboneimu->resetYaw();
}

void Chassis::liveWindow() {
	
}
