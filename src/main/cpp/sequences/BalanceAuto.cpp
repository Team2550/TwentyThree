#include "sequences/BalanceAuto.h"

BalanceAuto::BalanceAuto(DriveSubsystem* subsystem) {
	AddCommands(DriveForward(0.7, subsystem), frc2::WaitCommand(2.0_s), DriveForward(0.0, subsystem));
}
