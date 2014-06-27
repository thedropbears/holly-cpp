#include "TogglePimpin.h"


TogglePimpin :: TogglePimpin(): CommandBase ("TogglePimpin"){
    Requires (chassis);
}

void TogglePimpin::Initialize(){
	chassis->weBePimpin =! chassis->weBePimpin;
    chassis->gyroReset();
    chassis->gyro_pid->Reset();
}

void TogglePimpin::Execute(){
}

bool TogglePimpin::IsFinished(){
	return true;
}

void TogglePimpin::End(){
		
}

void TogglePimpin::Interrupted(){
}
