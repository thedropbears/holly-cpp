#include "../Robotmap.h"
#include "../CommandBase.h"
#include "PositionRobot.h"

#include <math.h>

void PositionRobot::Initialize() {
    Requires(CommandBase::chassis);
    CommandBase::chassis->weBePimpin=false;
}

void PositionRobot::Execute() {
    if(!CommandBase::eyebone->timedOut()) {
        target_x = CommandBase::eyebone->getTargetY(); //no i havent gone crazy, x, maps to y in the image
        target_y = CommandBase::eyebone->getTargetX();
        target_angle = CommandBase::eyebone->getTargetAngle();
        double vX = target_x - X_POS;
        double vY = target_y - Y_POS;
        double vZ = target_angle - ANGLE_POS;
        CommandBase::chassis->drive(vX, vY, vZ,1);
    }
}

bool PositionRobot::isFinished() {
    if(std::abs(target_x-X_POS) < X_TOL && std::abs(target_y-Y_POS) < Y_TOL && std::abs(target_angle-ANGLE_POS) < ANGLE_TOL)
        return true;
    return false;
}

void PositionRobot::Interrupted() {
    End();
}

void PositionRobot::End() {
    CommandBase::chassis->drive(0,0,0,0);
}
