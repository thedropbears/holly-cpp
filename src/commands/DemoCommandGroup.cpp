#include "DemoCommandGroup.h"
#include "SpinOneEighty.h"
#include "FindTarget.h"
#include "PositionRobot.h"

DemoCommandGroup::DemoCommandGroup() {
    AddSequential(new SpinOneEighty());
    AddSequential(new FindTarget());
    AddSequential(new PositionRobot());
}
