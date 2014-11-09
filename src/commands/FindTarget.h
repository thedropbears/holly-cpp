#ifndef FINDTARGET
#define FINDTARGET

#include <WPILib.h>

class FindTarget: public Command {
    public:
    private:
        static int directions[];
        int cmd_no = 0;
        virtual void Execute();
        virtual bool IsFinished();
        virtual void Interrupted();
        virtual void End();
        virtual void Initialize();
};

#endif
