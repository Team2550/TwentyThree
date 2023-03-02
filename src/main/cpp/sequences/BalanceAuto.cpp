#include "sequences/BalanceAuto.h"

BalanceAuto::BalanceAuto(DriveSubsystem* subsystem) { AddCommands(DriveForward(0.75, 1.5_m, subsystem)); }
