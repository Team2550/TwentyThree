#include "sequences/BalanceAuto.h"

#include "commands/DriveForwardTimed.h"

BalanceAuto::BalanceAuto(DriveSubsystem* subsystem) { AddCommands(DriveForwardTimed(0.6, 1.0_s, subsystem)); }
