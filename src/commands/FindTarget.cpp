#include "../Robotmap.h"
#include "../CommandBase.h"
#include "FindTarget.h"

#include <cstdlib>

void FindTarget::Execute() {
    if(CommandBase::chassis->gyro_pid->onTarget()) {
        CommandBase::chassis->setHeading(deg2rad(directions[cmd_no]));
        cmd_no++;
    }
}

bool FindTarget::isFinished() {
    if(abs(CommandBase::dropboneimu) < PI/3 && CommandBase::eyebone->getTargetWidth()!=0)
        return true;
    return false;
}
