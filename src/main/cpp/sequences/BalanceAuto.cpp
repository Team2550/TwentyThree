#include "sequences/BalanceAuto.h"

BalanceAuto::BalanceAuto(DriveSubsystem* subsystem) {
	AddCommands(DriveForward(-0.8, 0.15_m, subsystem), ArmHandTimed(ArmHandTimed::Value::kRelease, 2.0_s, subsystem),
		DriveForward(-0.5, 0.6_m, subsystem));
}
