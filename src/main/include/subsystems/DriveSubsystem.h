#pragma once

#include <frc/ADIS16470_IMU.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/Encoder.h>
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

	/***
	 * @brief Drives the robot.
	 *
	 * @param speedV The speed to move vertially.
	 * @param speedH The speed to move horizontally.
	 * @param rotation The rotation to steer the robot to.
	 */
	void MecanumDrive(double speedV, double speedH, double rotation);

	/***
	 * @brief Drives the robot using hybrid controls.
	 *
	 * @param leftSpeedV The speed to move the left motors vertially.
	 * @param leftSpeedH The speed to move the left motors horizontally.
	 *
	 * @param rightSpeedV The speed to move the right motors vertially.
	 * @param rightSpeedH The speed to move the right motors horizontally.
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