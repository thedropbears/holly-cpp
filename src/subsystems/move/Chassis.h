#ifndef Chassis_h
#define Chassis_h

#include <WPILib.h>

#include "../pid/GyroCorrection.h"

class Chassis: public Subsystem {
	public:
        Chassis();
        ~Chassis();
        void InitDefaultCommand();
        void drive(double vX, double vY, double vR, double throttle);
        void gyroReset();

        bool weBePimpin;
        PIDController *gyro_pid;

		void headingChange(double change);
        void setHeading(double newHeading);
	private:
        void liveWindow();

        Victor* driveMotorA;
        Victor* driveMotorB;
        Victor* driveMotorC;

        GyroCorrection *correction;
        bool momentum; // is the spin carrying on under momentum
};

#endif
