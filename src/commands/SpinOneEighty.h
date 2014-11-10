#ifndef SPINONEEIGHTY
#define SPINONEEIGHTY

#include <WPILib.h>

#include <CommandBase.h>

class SpinOneEighty: public CommandBase {
    public:
        SpinOneEighty();
        virtual void Execute();
        virtual bool IsFinished();
        virtual void Interrupted();
        virtual void End();
        virtual void Initialize();
    private:
        bool spinning = true;
};

#endif
