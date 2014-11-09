#ifndef POSITIONROBOT
#define POSITIONROBOT

#define DESIRED_IMAGE_Y 0.0
#define Y_TOL 0.1 // 1 is 100%

#define DESIRED_IMAGE_X 0.0 // the position on the screen UP AND DOWN of the target
#define X_TOL 0.1 // Absolute value that we can stray from X

#define DESIRED_IMAGE_ANGLE 0.0 // we want the angle to be 0
#define ANGLE_TOL 1 //degree

#include <WPILib.h>

#include "../CommandBase.h"

class PositionRobot: public CommandBase {
    public:
        PositionRobot();
    private:
        virtual void Execute();
        virtual bool IsFinished();
        virtual void Interrupted();
        virtual void End();
        virtual void Initialize();
        double vX, vY, vZ;
};

#endif
