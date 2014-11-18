#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "subsystems/move/Chassis.h"
#include "subsystems/move/Winch.h"
#include "lib/subsystems/DropBoneImu.h"
#include "subsystems/sensors/EyeBone.h"
#include "OI.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command {
public:
	CommandBase(const char *name);
    CommandBase(const char *name, double);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static Chassis *chassis;
	static OI *oi;
    static Winch *winch;
	static DropBoneImu* dropboneimu;
	static EyeBone* eyebone;
};

#endif
