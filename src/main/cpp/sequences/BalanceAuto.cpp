#include "sequences/BalanceAuto.h"

BalanceAuto::BalanceAuto(DriveSubsystem* subsystem) {
	AddCommands(DriveForward(0.75, 1.0_m, subsystem), DriveTurn(0.1, 90.0, subsystem),
				DriveForward(0.75, 1.0_m, subsystem), DriveTurn(0.1, 90.0, subsystem),
				DriveForward(0.75, 1.0_m, subsystem), DriveTurn(0.1, 90.0, subsystem),
				DriveForward(0.75, 1.0_m, subsystem), DriveTurn(0.1, 90.0, subsystem));
}
