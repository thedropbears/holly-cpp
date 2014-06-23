#include "OI.h"
#include "Robotmap.h"

OI::OI() {
    joyDrv = new Joystick(1);
}


Joystick* OI::getJoyDrv() {
	return joyDrv;
}

double OI :: applyDeadZone(double input, double deadZone){
	if(input <= - deadZone || input >= deadZone){
		return input;
	}
	return 0.0;
}

double OI::getJoyDrvX(){
	return applyDeadZone(joyDrv->GetX(), JOY_DRV_DEAD_X);
}

double OI::getJoyDrvY(){
	return applyDeadZone(joyDrv->GetY(), JOY_DRV_DEAD_Y);
}

double OI::getJoyDrvZ(){
	return applyDeadZone(joyDrv->GetZ(), JOY_DRV_DEAD_Z);
}

double OI::getJoyDrvThrottle(){
	return (joyDrv->GetTwist()-1.0)/2.0;
}
