#ifndef TogglePimpin_H
#define TogglePimpin_H

#include "../CommandBase.h"

class TogglePimpin: public CommandBase{
    public:    
        TogglePimpin();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
