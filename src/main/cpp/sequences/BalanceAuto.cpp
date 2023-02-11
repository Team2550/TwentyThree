#include "sequences/BalanceAuto.h"

#include "commands/DriveForwardTimed.h"

BalanceAuto::BalanceAuto(DriveSubsystem* subsystem) { AddCommands(DriveForward(0.5, 1.0_m, subsystem)); }
