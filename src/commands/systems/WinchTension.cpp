#include "WinchTension.h"
#include "../Robotmap.h"

WinchTension :: WinchTension(): CommandBase ("WinchTension"){
    Requires (winch);
}

void WinchTension::Initialize(){
	winch->TensionWinch(WINCH_MOTOR_SPEED);
}

void WinchTension::Execute(){
    winch->TensionWinch(WINCH_MOTOR_SPEED);
}

bool WinchTension::IsFinished(){
	return false;
}

void WinchTension::End(){
		
}

void WinchTension::Interrupted(){
    winch->TensionWinch(0.0);
}
