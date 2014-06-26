#ifndef GYRO_CORRECTION_H
#define GYRO_CORRECTION_H

#include <WPILib.h>

class GyroCorrection: public PIDOutput {
    public:
        GyroCorrection();
        void PIDWrite(float);
        float correction = 0;
};

#endif
