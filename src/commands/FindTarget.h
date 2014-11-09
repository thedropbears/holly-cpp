#ifndef FINDTARGET
#define FINDTARGET

#include <WPILib.h>

#include "../CommandBase.h"

class FindTarget: public CommandBase {
    public:
        FindTarget();
        virtual void Execute();
        virtual bool IsFinished();
        virtual void Interrupted();
        virtual void End();
        virtual void Initialize();
    private:
        static int directions[];
        int cmd_no = 0;
};

#endif
