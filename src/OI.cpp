#include "OI.h"
#include "Robotmap.h"

#include "commands/WinchLoosen.h"
#include "commands/WinchTension.h"
#include "commands/GyroReset.h"
#include "commands/TogglePimpin.h"
#include "commands/DemoCommandGroup.h"

OI::OI() {
    joyDrv = new Joystick(1);
    
    winchTensionButton = new JoystickButton (joyDrv, WINCH_TENSION_BUTTON);
    winchTensionButton->WhileHeld(new WinchTension());
    
    winchLoosenButton = new JoystickButton (joyDrv, WINCH_LOOSEN_BUTTON);
    winchLoosenButton->WhileHeld(new WinchLoosen());
    
    gyroResetButton = new JoystickButton (joyDrv, GYRO_RESET_BUTTON);
    gyroResetButton->WhenPressed(new GyroReset());
    
    pimpButton = new JoystickButton (joyDrv, PIMP_ROLL_BUTTON);
    pimpButton->WhenPressed(new TogglePimpin());
    
    DemoCommandGroup* demo_group = new DemoCommandGroup();
    
    demoButton = new JoystickButton (joyDrv, DEMO_BUTTON);
    demoButton->WhenPressed(demo_group);
    
    demoCancel = new JoystickButton (joyDrv, DEMO_CANCEL_BUTTON);
    demoCancel->CancelWhenPressed(demo_group);
}


Joystick* OI::getJoyDrv() {
	return joyDrv;
}

double OI :: applyDeadZone(double input, double deadZone){
	if(input <= - deadZone || input >= deadZone){
		return input;
	}
	return 0.0;
}

double OI::getJoyDrvX(){
	return applyDeadZone(joyDrv->GetX(), JOY_DRV_DEAD_X);
}

double OI::getJoyDrvY(){
	return applyDeadZone(joyDrv->GetY(), JOY_DRV_DEAD_Y);
}

double OI::getJoyDrvZ(){
	return applyDeadZone(joyDrv->GetZ(), JOY_DRV_DEAD_Z);
}

double OI::getJoyDrvThrottle(){
	return (joyDrv->GetTwist()-1.0)/2.0;
}

