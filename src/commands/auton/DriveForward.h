#ifndef DriveForward_h
#define DriveForward_h

#include <CommandBase.h>

class DriveForward: public CommandBase{
	public:
		DriveForward();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};

#endif
