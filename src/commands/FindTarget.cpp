#include <Robotmap.h>
#include "FindTarget.h"

#include <math.h>

int FindTarget::directions[] = {178, 157, 135, -157, -135};

FindTarget::FindTarget(): CommandBase("FindTarget") {
}

void FindTarget::Initialize() {
    Requires(chassis);
    chassis->gyro_pid->Enable();
    chassis->weBePimpin=true;
}

void FindTarget::End() {
    chassis->gyro_pid->Disable();
    chassis->weBePimpin=false;
    chassis->drive(0,0,0,0);
}

void FindTarget::Interrupted() {
    End();
}

void FindTarget::Execute() {
    if(chassis->gyro_pid->OnTarget() && cmd_no < sizeof directions/sizeof(unsigned int)) {
        chassis->setHeading(deg2rad(directions[cmd_no]));
        cmd_no++;
    }
}

bool FindTarget::IsFinished() {
    if(std::abs(PI-dropboneimu->getYawAngle()) < PI/3 && eyebone->getTargetWidth()!=0)
        return true;
    return false;
}
