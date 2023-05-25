#pragma once


#include <frc/PowerDistribution.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/drive/MecanumDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class DriveSubsystem : public frc2::SubsystemBase {
public:
	DriveSubsystem();

	/**
 	 * @brief Drives mecanum wheels in arcade style
 	 *
 	 * Intended for use in 'arcade' style controls, where 1 stick controls movement
 	 * and the other controls rotation. 
 	 *
 	 * @param[in] speedV The speed in which the robot moves forward/backwards.
 	 * @param[in] speedH The speed in which the robot moves left/right.
 	 * @param[in] rotation The speed in which the direction the robot is facing is changed.
 	 */
	void MecanumDrive(double speedV, double speedH, double rotation);

	/**
 	 * @brief Drives mecanum wheels in tank style
 	 *
 	 * Intended for use in 'tank/west-coast/differential' style controls, 
 	 * where 1 stick controls the left side, and the other controls the right.
 	 *
 	 * @param[in] leftSpeedV The speed in which the left wheels move forward/backwards.
 	 * @param[in] leftSpeedH The speed in which the left wheels move the robot left/right.
 	 * @param[in] rightSpeedV The speed in which the right wheels move forward/backwards.
 	 * @param[in] rightSpeedH The speed in which the right wheels move the robot left/right.
	 *
 	 */
	void MecanumTankDrive(double leftSpeedV, double leftSpeedH, double rightSpeedV, double rightSpeedH);

private:
	// Motor Controllers
	frc::Spark m_frontLeft;
	frc::Spark m_rearLeft;
	frc::MotorControllerGroup m_left { m_frontLeft, m_rearLeft };

	frc::Spark m_frontRight;
	frc::Spark m_rearRight;
	frc::MotorControllerGroup m_right { m_frontRight, m_rearRight };

	// Drive Controller
	frc::MecanumDrive m_drive { m_frontLeft, m_rearLeft, m_frontRight, m_rearRight };
};