#include <Robotmap.h>
#include <CommandBase.h>
#include "PositionRobot.h"

#include <math.h>

PositionRobot::PositionRobot(): CommandBase("PositionRobot"){
}

void PositionRobot::Initialize() {
    chassis->weBePimpin=false;
}

void PositionRobot::Execute() {
    if(!eyebone->timedOut()) {
        
        vX = eyebone->getTargetY() - DESIRED_IMAGE_Y;
        vY = eyebone->getTargetX() - DESIRED_IMAGE_X;
        vZ = (eyebone->getTargetAngle() - DESIRED_IMAGE_ANGLE)/45;
        chassis->drive(vX, vY, vZ,1);
    }
}

bool PositionRobot::IsFinished() {
    if(std::abs(vX) < X_TOL && std::abs(vY) < Y_TOL && std::abs(vZ) < ANGLE_TOL)
        return true;
    return false;
}

void PositionRobot::Interrupted() {
    End();
}

void PositionRobot::End() {
    chassis->drive(0,0,0,0);
}
