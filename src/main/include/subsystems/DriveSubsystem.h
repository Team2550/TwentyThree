#pragma once

#include <frc/Encoder.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/Spark.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class DriveSubsystem : public frc2::SubsystemBase {
   public:
	DriveSubsystem();

	/***
	 * @brief Drives the robot using tank controls.
	 *
	 * @param leftSpeed The speed for the left wheels.
	 * @param rightSpeed The speed for the right wheels.
	 */
	void TankDrive(double leftSpeed, double rightSpeed);

	/**
	 * @brief Resets the drive encoders to read zero.
	 */
	void ResetEncoders();

	/**
	 * @brief Gets the left drive encoder.
	 */
	frc::Encoder& GetLeftEncoder();

	/**
	 * @brief Gets the right drive encoder.
	 */
	frc::Encoder& GetRightEncoder();

	/**
	 * Sets the output scalar.
	 *
	 * @param scale The value to scale the output by (0-1).
	 */
	void SetOutputScale(double scale);

   private:
	// Motor Controllers
	frc::Spark m_left;
	frc::Spark m_right;

	// Encoders
	frc::Encoder m_leftEncoder;
	frc::Encoder m_rightEncoder;

	// Drive Controller
	frc::DifferentialDrive m_drive{m_left, m_right};
};