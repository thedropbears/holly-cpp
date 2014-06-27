#include "HolonomicDrive.h"
#include "../Robotmap.h"

HolonomicDrive::HolonomicDrive():CommandBase("HolonomicDrive"){
	Requires(chassis);
}

void HolonomicDrive::Initialize(){
	
}

void HolonomicDrive::Execute(){
	
    double x = -oi->getJoyDrvY();
    double y = -oi->getJoyDrvX();
    double z = oi->getJoyDrvZ();
    double throttle = oi->getJoyDrvThrottle();

    
    chassis->drive(x, y, z, throttle);
    
    SmartDashboard::PutNumber("Joystick x", x);
    SmartDashboard::PutNumber("Joystick y", y);
    SmartDashboard::PutNumber("Joystick z", z);
    SmartDashboard::PutNumber("Joystick throttle", throttle);
}

bool HolonomicDrive::IsFinished(){
	return false;
}

void HolonomicDrive::End(){
		
}

void HolonomicDrive::Interrupted(){
	chassis->drive(0,0,0,0);
}
