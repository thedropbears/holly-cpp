#include <Robotmap.h>
#include "FindTarget.h"

#include <math.h>

//int FindTarget::directions[] = {178};//, 157, 135, -157, -135};

FindTarget::FindTarget(): CommandBase("FindTarget") {
}

void FindTarget::Initialize() {
    chassis->gyro_pid->Enable();
    chassis->weBePimpin=true;
    chassis->setHeading(deg2rad(178));
    printf("Initialized\n");
    chassis->drive(0,0,0,1);
}

void FindTarget::End() {
    chassis->gyro_pid->Disable();
    //chassis->weBePimpin=false;
    chassis->drive(0,0,0,1);
    printf("Ending the method\n");
}

void FindTarget::Interrupted() {
    End();
}

void FindTarget::Execute() {
	/*
    if(chassis->gyro_pid->OnTarget() && cmd_no < sizeof directions/sizeof(unsigned int)) {
        chassis->setHeading(deg2rad(directions[cmd_no]));
        cmd_no++;
    }
    */
    chassis->setHeading(deg2rad(178));
    printf("Executing \n");
}

bool FindTarget::IsFinished() {
	/*
    if(std::abs(PI-dropboneimu->getYawAngle()) < PI/3 && eyebone->getTargetWidth()!=0)
        return true;
    return false;
    */
    if(chassis->gyro_pid->OnTarget()) {
        printf("Finishd bro\n");
        return true;
	}
	printf("Not finished\n");
    return false;
}
