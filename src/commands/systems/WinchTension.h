#ifndef WinchTension_H
#define WinchTension_H

#include <CommandBase.h>

class WinchTension: public CommandBase{
    public:
        WinchTension();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
    
};

#endif 
