#include "AutonTension.h"
#include "../Robotmap.h"

AutonTension :: AutonTension(): CommandBase ("AutonTension"){
    Requires (winch);
    SetTimeout(2);
}

void AutonTension::Initialize(){
	winch->TensionWinch(WINCH_MOTOR_SPEED);
}

void AutonTension::Execute(){
    winch->TensionWinch(WINCH_MOTOR_SPEED);
}

bool AutonTension::IsFinished(){
	return IsTimedOut();
}

void AutonTension::End(){
		
}

void AutonTension::Interrupted(){
    winch->TensionWinch(0.0);
}
