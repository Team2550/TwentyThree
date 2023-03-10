#pragma once

#include <frc/Encoder.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/ADIS16470_IMU.h>

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
	 * @brief Gets the current yaw of the IMU.
	 * 
	 * @param imuAxis The axis to return the Angle for.
	 * 
	 * 0 returns X axis;
	 * 1 returns Y axis;
	 * 2 returns Z axis.
	*/
	units::angle::degree_t GetCurrentAngle(frc::ADIS16470_IMU::IMUAxis imuAxis);

	/**
	 * Sets the output scalar.
	 *
	 * @param scale The value to scale the output by (0-1).
	 */
	void SetOutputScale(double scale);

   private:
	// Motor Controllers
	frc::Spark m_frontLeft;
	frc::Spark m_rearLeft;
	frc::MotorControllerGroup m_left{m_frontLeft, m_rearLeft};

	frc::Spark m_frontRight;
	frc::Spark m_rearRight;
	frc::MotorControllerGroup m_right{m_frontRight, m_rearRight};

	// Encoders
	frc::Encoder m_leftEncoder;
	frc::Encoder m_rightEncoder;

	// Gyro
	frc::ADIS16470_IMU m_imu;

	// Drive Controller
	frc::DifferentialDrive m_drive{m_left, m_right};

};