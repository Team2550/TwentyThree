#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/Commands.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/PrintCommand.h>
#include <frc2/command/ScheduleCommand.h>
#include <frc2/command/WaitCommand.h>

#include <cmath>

#include "subsystems/DriveSubsystem.h"

class BalanceAuto : public frc2::CommandHelper<frc2::CommandBase, BalanceAuto> {
   public:
	/**
	 * Creates a new BalanceAuto.
	 *
	 * @param time The amount of seconds that the robot will drive.
	 * @param speed The speed at which the robot will drive
	 * @param drive The drive subsystem on which this command will run
	 */
	explicit BalanceAuto(double inches, double speed, DriveSubsystem* subsystem);

	void Initialize() override;

	void Execute() override;

	void End(bool interrupted) override;

	bool IsFinished() override;

   private:
	DriveSubsystem* m_drive;
	double m_speed;
	double m_distance;
	bool m_isComposed = true;
};