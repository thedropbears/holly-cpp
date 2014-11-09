#include <math.h>

#include "Chassis.h"
#include <Robotmap.h>
#include <commands/HolonomicDrive.h>
#include <CommandBase.h> 

#define GYRO_P (-0.005)
#define GYRO_I (0.0)
#define GYRO_D (0.0)

Chassis::Chassis(): Subsystem("Chassis") {
    driveMotorA = new Victor (MOTOR_A_PWM);
    driveMotorB = new Victor (MOTOR_B_PWM);
    driveMotorC = new Victor (MOTOR_C_PWM);
    
    
    correction = new GyroCorrection();
    gyro_pid = new PIDController(GYRO_P, GYRO_I, GYRO_D, CommandBase::dropboneimu,correction);
    gyro_pid->SetInputRange(-PI, PI);
    gyro_pid->SetSetpoint(0.0);
    gyro_pid->Enable();
    
    weBePimpin = true;
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
        double heading = CommandBase::dropboneimu->getYawAngle();
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
        if (vZ == 0 || (abs(CommandBase::dropboneimu->getYawRate()) < PID_THRESHOLD && gyro_pid->IsEnabled())) {
            vZ = correction->correction;
        } else {
            double SetHeading = CommandBase::dropboneimu->getYawAngle();
            gyro_pid->Reset();
            gyro_pid->SetSetpoint(SetHeading);
            gyro_pid->Enable();
            correction->correction = 0;
        }
    }

    vMotor[0] = (vX*0) - vY -vZ;
    vMotor[1] = -(vX + vY/2.0 -vZ);
    vMotor[2] = -(-vX + vY/2.0 -vZ);

    double vmax = 1.0; // sets maximum value to 1
    for(int i = 0; i < 3; ++i){
    if(abs(vMotor[i]) >vmax )
        vmax =abs (vMotor [i]); // sets the absolute motor value to vmax 
            //if it is greater than 1 
    }

    // takes the votor values and scales them according to what vmax * throttle is 
    for (int i = 0; i < 3; ++i) {
        vMotor[i] = vMotor[i]/vmax*throttle;
    }
    driveMotorA->Set(vMotor[0]);
    driveMotorB->Set(-vMotor[1]);
    driveMotorC->Set(-vMotor[2]);

    SmartDashboard::PutNumber("Motor A", vMotor[0]);
    SmartDashboard::PutNumber("Motor B", vMotor[1]);
    SmartDashboard::PutNumber("Motor C", vMotor[2]);
    SmartDashboard::PutNumber("Heading setpoint (deg)", rad2deg(gyro_pid->GetSetpoint()));
    SmartDashboard::PutNumber("Control loop output", correction->correction);
    SmartDashboard::PutBoolean("Are we Pimpin", weBePimpin);
}


void Chassis::gyroReset() {
    gyro_pid->Reset();
    CommandBase::dropboneimu->resetYaw();
    gyro_pid->SetSetpoint(0.0);
    gyro_pid->Enable();
}

void Chassis::liveWindow() {
}

void Chassis::setHeading(double newHeading) {
    gyro_pid->Reset();
    gyro_pid->SetSetpoint(newHeading);
    gyro_pid->Enable();
}

void Chassis::headingChange(double change) {
    gyro_pid->Reset();
    double newHead = CommandBase::dropboneimu->getYawAngle()+change;
    newHead = atan2(sin(newHead),cos(newHead)); //wrap to +- PI
    gyro_pid->SetSetpoint(newHead);
    gyro_pid->Enable();
}
