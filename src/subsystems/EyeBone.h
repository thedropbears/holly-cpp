#ifndef EYEBONE
#define EYEBONE

#include <subsystems/UdpReceiver.h>

#define EYE_PARSEDLEN 5 // the number of elements we are expecting from the string that we will be parsing

class EyeBone: public UdpReceiver {
    public:
        EyeBone(int port=4775);
        ~EyeBone();
        double getTargetX();
        double getTargetY();
        double getTargetWidth();
        double getTargetHeight();
        double getTargetAngle();
    private:
        double parsed[EYE_PARSEDLEN];
        virtual int parsePacket(char* recv_buffer, int received_bytes);
};

#endif
