#include "WPILib.h"
#include "commands/AutonomousCommandGroup.h"
#include "CommandBase.h"
#include "Holly.h"

Holly :: Holly(){
    
}

void Holly :: RobotInit() {
    CommandBase::init();
    autonomousCommand = new AutonomousCommandGroup();
    lw = LiveWindow::GetInstance();
}
	
void Holly :: AutonomousInit() {
    CommandBase::chassis->gyroReset();
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

    SmartDashboard::PutData(CommandBase::dropboneimu);
    SmartDashboard::PutNumber("Yaw Angle: ", CommandBase::dropboneimu->getYawAngle()/3.14*180);
    SmartDashboard::PutNumber("Yaw Rate: ", CommandBase::dropboneimu->getYawRate()/3.14*180);

    SmartDashboard::PutData(CommandBase::eyebone);
    SmartDashboard::PutNumber("Target X: ", CommandBase::eyebone->getTargetX());
    SmartDashboard::PutNumber("Target Y: ", CommandBase::eyebone->getTargetY());
    SmartDashboard::PutNumber("Target Angle: ", CommandBase::eyebone->getTargetAngle());
}

void Holly :: DisabledPeriodic() {
    smartDashboard();
}

START_ROBOT_CLASS(Holly);

