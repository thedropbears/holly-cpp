#include "GyroCorrection.h"

GyroCorrection :: GyroCorrection() {
    
}

void GyroCorrection :: PIDWrite(float output) {
	if (output > 0.5) {
		correction = 0.5;
	} else {
		correction = output;
	}
}
