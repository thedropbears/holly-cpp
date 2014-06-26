#ifndef Winch_h
#define Winch_h

#include <WPILib.h>

class Winch: public Subsystem{
    public:
        Winch();
        ~Winch();
        void TensionWinch(double speed);
        
    private:
        Victor *winchmotor;

};

#endif
