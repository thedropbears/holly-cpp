#ifndef WinchLoosen_H
#define WinchLoosen_H

#include <CommandBase.h>

class WinchLoosen: public CommandBase{
    public:
        WinchLoosen();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
    
};

#endif 
