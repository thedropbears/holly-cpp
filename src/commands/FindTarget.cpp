#include "../Robotmap.h"
#include "../CommandBase.h"
#include "FindTarget.h"

#include <math.h>

int directions[] = {180, 157, 135, -157, -135};

void FindTarget::Initialize() {
    Requires(CommandBase::chassis);
    CommandBase::chassis->gyro_pid->Enable();
    CommandBase::chassis->weBePimpin=true;
}

void FindTarget::End() {
    CommandBase::chassis->gyro_pid->Disable();
    CommandBase::chassis->weBePimpin=false;
    CommandBase::chassis->drive(0,0,0,0);
}

void FindTarget::Interrupted() {
    End();
}

void FindTarget::Execute() {
    if(CommandBase::chassis->gyro_pid->OnTarget()) {
        CommandBase::chassis->setHeading(deg2rad(directions[cmd_no]));
        cmd_no++;
    }
}

bool FindTarget::isFinished() {
    if(std::abs(CommandBase::dropboneimu->getYawAngle()) < PI/3 && CommandBase::eyebone->getTargetWidth()!=0)
        return true;
    return false;
}
