#include "SpinOneEighty.h"

#include <Robotmap.h>

SpinOneEighty::SpinOneEighty(): CommandBase("SpinOneEighty") {
}

void SpinOneEighty::Initialize() {
    chassis->gyro_pid->Enable();
    chassis->weBePimpin=true;
}

void SpinOneEighty::Execute() {
    if(!spinning) {
        chassis->headingChange(deg2rad(180)); //spin one eighty!
        spinning = true;
    }
}

bool SpinOneEighty::IsFinished(){
    if(chassis->gyro_pid->OnTarget())
        return true;
    return false;
}

void SpinOneEighty::Interrupted() {
    End();
}

void SpinOneEighty::End() {
    chassis->gyro_pid->Disable();
    chassis->weBePimpin=false;
    chassis->drive(0,0,0,0);
}
