#ifndef EYEBONE
#define EYEBONE

#include <subsystems/UdpReceiver.h>

#define PORT 4775

#define PARSEDLEN 5 // the number of elements we are expecting from the string that we will be parsing

class EyeBone: public UdpReceiver {
    public:
        EyeBone();
        ~EyeBone();
        double getTargetX();
        double getTargetY();
        double getTargetWidth();
        double getTargetHeight();
        double getTargetAngle();
    private:
        double parsed[5];
        virtual int parseBroadcast(char* recv_buffer, int received_bytes);
};

#endif
