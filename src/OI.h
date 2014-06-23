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
        
        double applyDeadZone(double,double);
};

#endif
