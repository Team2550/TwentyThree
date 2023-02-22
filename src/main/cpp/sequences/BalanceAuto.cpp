#include "sequences/BalanceAuto.h"

BalanceAuto::BalanceAuto(DriveSubsystem* subsystem) {
	AddCommands(DriveForward(0.75, 1.5_m, subsystem), WaitCommand(0.5_s), DriveTurn(0.1, 90.0, subsystem),
		WaitCommand(0.5_s), DriveForward(0.75, 1.5_m, subsystem), WaitCommand(0.5_s), DriveTurn(0.1, 90.0, subsystem));
	/*AddCommands(DriveForward(0.75, 1.5_m, subsystem), WaitCommand(0.5_s), DriveTurn(0.1, 90.0, subsystem),
		WaitCommand(0.5_s), DriveForward(0.75, 1.5_m, subsystem), WaitCommand(0.5_s), DriveTurn(0.1, 90.0, subsystem),
		WaitCommand(0.5_s), DriveForward(0.75, 1.5_m, subsystem), WaitCommand(0.5_s), DriveTurn(0.1, 90.0, subsystem),
		WaitCommand(0.5_s), DriveForward(0.75, 1.5_m, subsystem), WaitCommand(0.5_s), DriveTurn(0.1, 90.0,
	   subsystem));*/
}
