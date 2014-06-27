#include "AutonomousCommandGroup.h"
#include "Driveforward.h"
#include "AutonTension.h"


AutonomousCommandGroup::AutonomousCommandGroup() {
    AddSequential (new DriveForward());
    AddSequential (new AutonTension());
}
