#include "DemoCommandGroup.h"
#include "SpinOneEighty.h"
#include "FindTarget.h"
#include "PositionRobot.h"

DemoCommandGroup::DemoCommandGroup() {
    AddSequential(new SpinOneEighty()); // so sponsors know that we are not cheating
    AddSequential(new FindTarget());
    AddSequential(new PositionRobot());
    AddSequential(new SpinOneEighty()); // get ready to fire
}
