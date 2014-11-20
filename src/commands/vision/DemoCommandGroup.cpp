#include "DemoCommandGroup.h"
#include "SpinOneEighty.h"
#include "FindTarget.h"
#include "PositionRobot.h"
#include "../systems/WinchTension.h"

DemoCommandGroup::DemoCommandGroup(): CommandGroup("AutoShooting") {
    Requires(CommandBase::chassis);
    AddSequential(new FindTarget());
    AddSequential(new PositionRobot());
    AddSequential(new SpinOneEighty()); // get ready to fire
    AddSequential(new WinchTension());
}
