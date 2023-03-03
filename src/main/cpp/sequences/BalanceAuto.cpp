#include "sequences/BalanceAuto.h"

BalanceAuto::BalanceAuto(DriveSubsystem* subsystem) {
	AddCommands(DriveForwardTimed(-1, 0.5_s, subsystem), DriveForwardTimed(0.25, 2_s, subsystem),
		ArmHand(ArmHand::Value::kRelease, subsystem));
}
