#ifndef Chassis_h
#define Chassis_h

#include <WPILib.h>

#include "GyroCorrection.h"

class Chassis: public Subsystem {
	public:
        Chassis();
        ~Chassis();
        void InitDefaultCommand();
        void drive(double vX, double vY, double vR, double throttle);
        void gyroReset();
        
        bool weBePimpin;
	private:
        void liveWindow();
        
        Victor* driveMotorA;
        Victor* driveMotorB;
        Victor* driveMotorC;
        
        Gyro* gyro;
        GyroCorrection *correction;
        PIDController *gyro_pid;
        
        
        
        double SetHeading;
	
};

#endif
