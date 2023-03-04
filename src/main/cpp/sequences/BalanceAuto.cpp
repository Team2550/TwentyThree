#include "sequences/BalanceAuto.h"

BalanceAuto::BalanceAuto(DriveSubsystem* subsystem) {
	AddCommands(DriveForward(-0.8, 0.25_m, subsystem), DriveForward(0.5, 0.5_m, subsystem),
		ArmHand(ArmHand::Value::kGrab, subsystem), WaitCommand(3_s), DriveForward(-0.5, 0.5_m, subsystem));
}
