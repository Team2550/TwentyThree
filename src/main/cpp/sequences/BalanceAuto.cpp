#include "sequences/BalanceAuto.h"

BalanceAuto::BalanceAuto(DriveSubsystem* subsystem) {
	AddCommands(DriveForward(-0.5, 0.25_m, subsystem), DriveForward(0.25, 1_m, subsystem),
		ArmHand(ArmHand::Value::kRelease, subsystem));
}
