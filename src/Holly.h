#ifndef Holly_h
#define Holly_h

#include "WPILib.h"

class Holly : public IterativeRobot {
    private:
        Command *autonomousCommand;
        LiveWindow *lw;
        void smartDashboard();
        
    public:
		Holly();
        void RobotInit();
        void AutonomousInit();
        void AutonomousPeriodic();
        void TeleopInit();
        void TeleopPeriodic();
        void TestInit();
        void TestPeriodic();
		void DisabledPeriodic();
};

#endif
