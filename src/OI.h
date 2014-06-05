#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick* joyDrv;
	Joystick* joyOpr;
	double applyDeadZone(double,double);
public:
	OI();
	Joystick* getJoyDrv();
	Joystick* getJoyOpr();
	double getJoyDrvX();
	double getJoyDrvY();
	double getJoyDrvZ();
	double getJoyDrvThrottle();
};

#endif
