#ifndef Chassis_h
#define Chassis_h

#include <WPILib.h>

class Chassis: public Subsystem {
	public:
        Chassis();
        ~Chassis();
        void InitDefaultCommand();
        void drive(double vX, double vY, double vR, double throttle);
	
	private:
        void liveWindow();
        
        Victor* driveMotorA;
        Victor* driveMotorB;
        Victor* driveMotorC;
	
};

#endif
