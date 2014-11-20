#include "DriveForward.h"
#include "../Robotmap.h"

DriveForward::DriveForward():CommandBase("DriveForward"){
	Requires(chassis);
	SetTimeout(2.5);
}

void DriveForward::Initialize(){	
	
}

void DriveForward::Execute(){
	chassis->drive(1, 0, 0, 1);
    
}

bool DriveForward::IsFinished(){
	return IsTimedOut();
}

void DriveForward::End(){
	chassis->drive (0,0,0,0);
}

void DriveForward::Interrupted(){
	End();
}	
