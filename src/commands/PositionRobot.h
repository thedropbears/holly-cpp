#ifndef POSITIONROBOT
#define POSITIONROBOT

#define Y_POS 0.0
#define Y_TOL 0.1 // 1 is 100%

#define X_POS 0.0 // the position on the screen UP AND DOWN of the target
#define X_TOL 0.1 // Absolute value that we can stray from X

#define ANGLE_POS 0.0 // we want the angle to be 0
#define ANGLE_TOL 1 //degree

#include <WPILib.h>

class PositionRobot: public Command {
    public:
    private:
        virtual void Execute();
        virtual bool isFinished();
        virtual void Interrupted();
        virtual void End();
        virtual void Initialize();
        double target_x, target_y, target_angle;
};

#endif
