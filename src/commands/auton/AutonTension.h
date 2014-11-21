#ifndef AutonTension_H
#define AutonTension_H

#include <CommandBase.h>

class AutonTension: public CommandBase{
    public:
        AutonTension();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
    
};

#endif 
