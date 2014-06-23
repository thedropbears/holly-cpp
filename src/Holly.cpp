#include "WPILib.h"
#include "commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Holly.h"

Holly :: Holly(){
    
}

void Holly :: RobotInit() {
    CommandBase::init();
    autonomousCommand = new ExampleCommand();
    lw = LiveWindow::GetInstance();
}
	
void Holly :: AutonomousInit() {
    autonomousCommand->Start();
}
	
void Holly :: AutonomousPeriodic() {
    Scheduler::GetInstance()->Run();
}
	
void Holly :: TeleopInit() {
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to 
    // continue until interrupted by another command, remove
    // this line or comment it out.
    autonomousCommand->Cancel();
}
	
void Holly::TeleopPeriodic() {
    Scheduler::GetInstance()->Run();
    smartDashboard();
}

void Holly :: TestInit() {
    
}
	
void Holly :: TestPeriodic() {
    lw->Run();
}

void Holly :: smartDashboard() {
	// Update the Smart Dashboard values
	// Call from TeleopPeriodic and AutonomousPeriodic
    SmartDashboard::PutData(Scheduler::GetInstance());
    
    SmartDashboard::PutData(CommandBase::chassis);
}

START_ROBOT_CLASS(Holly);

