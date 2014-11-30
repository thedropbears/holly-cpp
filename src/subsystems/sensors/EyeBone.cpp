#include "EyeBone.h"

#include <cstdlib>

EyeBone::EyeBone(int port): UdpReceiver(port, "EyeBone"){
}

EyeBone::~EyeBone() {
}

EyeBone::subSocketInit() {
    
}

EyeBone::subReceivePacket() {
    
}

int EyeBone::parsePacket(char* recv_buffer, int received_bytes) {
    char* end = recv_buffer;
    double next;
    for(int i = 0; i < EYE_PARSEDLEN; i++){
        next=strtod(end+1,&end);
        parsed[i] = next;
    }
    return 0;
}

double EyeBone::getTargetX() {
    return parsed[0];
}

double EyeBone::getTargetY() {
    return parsed[1];
}

double EyeBone::getTargetWidth() {
    return parsed[2];
}

double EyeBone::getTargetHeight() {
    return parsed[3];
}

double EyeBone::getTargetAngle() {
    return parsed[4];
}
