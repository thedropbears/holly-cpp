#include "GyroReset.h"


GyroReset :: GyroReset(): CommandBase ("GyroReset"){
    Requires (chassis);
}

void GyroReset::Initialize(){
	chassis->gyroReset();
}

void GyroReset::Execute(){
}

bool GyroReset::IsFinished(){
	return true;
}

void GyroReset::End(){
		
}

void GyroReset::Interrupted(){
}
