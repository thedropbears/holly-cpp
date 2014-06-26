#include "GyroCorrection.h"

GyroCorrection :: GyroCorrection() {
    
}

void GyroCorrection :: PIDWrite(float output) {
    correction = output;
}
