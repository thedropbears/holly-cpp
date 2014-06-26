#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
    public:
        OI();
        
        Joystick* getJoyDrv();
        double getJoyDrvX();
        double getJoyDrvY();
        double getJoyDrvZ();
        double getJoyDrvThrottle();
        
    private:
        Joystick* joyDrv;
        Button* winchTensionButton;
        Button* winchLoosenButton;
        Button* gyroResetButton;
        Button* pimpButton;
        
        double applyDeadZone(double,double);
};

#endif
