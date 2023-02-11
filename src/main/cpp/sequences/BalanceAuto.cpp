#include "sequences/BalanceAuto.h"

#include "commands/DriveForwardTimed.h"

BalanceAuto::BalanceAuto(DriveSubsystem* subsystem) { AddCommands(DriveForward(1, 1.0_m, subsystem)); }
