#ifndef Chassis_h
#define Chassis_h

#include <WPILib.h>

class Chassis: public Subsystem {
	public:
	Chassis();
	~Chassis();
	void InitDefaultCommand();
	void drive();
	
	private:
	void liveWindow();
	
};

#endif
