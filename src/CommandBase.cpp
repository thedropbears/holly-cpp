#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase(const char *name, double) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
Chassis* CommandBase::chassis = NULL;
Winch* CommandBase::winch = NULL;
DropBoneImu* CommandBase::dropboneimu = NULL;
EyeBone* CommandBase::eyebone = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
    chassis = new Chassis();
    winch = new Winch();
    oi = new OI();
    dropboneimu = new DropBoneImu();
    eyebone = new EyeBone();
}
