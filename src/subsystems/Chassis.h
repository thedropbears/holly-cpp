#ifndef Chassis_h
#define Chassis_h

#include <WPILib.h>

#define PI 3.14159

#include "GyroCorrection.h"

class Chassis: public Subsystem {
	public:
        Chassis();
        ~Chassis();
        void InitDefaultCommand();
        void drive(double vX, double vY, double vR, double throttle);
        void gyroReset();
        
        bool weBePimpin;
        PIDController *gyro_pid;
	private:
        void liveWindow();
        
        Victor* driveMotorA;
        Victor* driveMotorB;
        Victor* driveMotorC;
        
        GyroCorrection *correction;

        
        
        
        double SetHeading;
	
};

#endif
