#include "Winch.h"
#include "../Robotmap.h"

Winch :: Winch(): Subsystem ("Winch") {
    winchmotor = new Victor (WINCH_MOTOR_PWM);
}

Winch :: ~Winch() {
    delete winchmotor;
} 

void Winch :: TensionWinch(double speed) {
    winchmotor->Set(speed);
}
