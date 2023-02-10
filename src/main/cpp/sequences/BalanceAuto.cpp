#include "sequences/BalanceAuto.h"

#include "commands/DriveForwardTimed.h"

BalanceAuto::BalanceAuto(DriveSubsystem* subsystem) { AddCommands(DriveForwardTimed(0.5, 5.0_s, subsystem)); }
