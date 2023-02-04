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

class DriveForward : public frc2::CommandHelper<frc2::CommandBase, DriveForward> {
   public:
	/**
	 * Creates a new DriveForward.
	 *
	 * @param speed The speed at which the robot will drive
	 * @param drive The drive subsystem on which this command will run
	 */
	explicit DriveForward(double speed, DriveSubsystem* subsystem);

	/**
	 * Creates a new DriveForward.
	 *
	 * @param speed The speed at which the robot will drive.
	 * @param distance The distance the robot will drive.
	 * @param drive The drive subsystem on which this command will run.
	 */
	explicit DriveForward(double speed, double distance, DriveSubsystem* subsystem);

	void Initialize() override;

	void Execute() override;

	void End(bool interrupted) override;

	bool IsFinished() override;

   private:
	DriveSubsystem* m_drive;
	std::optional<double> m_distance;
	double m_speed;
};