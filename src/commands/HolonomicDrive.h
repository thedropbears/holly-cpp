#ifndef HolonomicDrive_h
#define HolonomicDrive_h

#include "../CommandBase.h"

class HolonomicDrive: public CommandBase{
	public:
		HolonomicDrive();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
