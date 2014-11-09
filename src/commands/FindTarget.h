#ifndef FINDTARGET
#define FINDTARGET

#include <WPILib.h>

#include "../CommandBase.h"

class FindTarget: public CommandBase {
    public:
        FindTarget();
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
