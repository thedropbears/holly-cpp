#include "WinchLoosen.h"
#include "../Robotmap.h"

WinchLoosen :: WinchLoosen(): CommandBase ("WinchLoosen"){
    Requires (winch);
}

void WinchLoosen::Initialize(){
	winch->TensionWinch(-WINCH_MOTOR_SPEED);
}

void WinchLoosen::Execute(){
    winch->TensionWinch(-WINCH_MOTOR_SPEED);
}

bool WinchLoosen::IsFinished(){
	return false;
}

void WinchLoosen::End(){
		
}

void WinchLoosen::Interrupted(){
    winch->TensionWinch(0.0);
}
