#include "subsystems/DriveSubsystem.h"

using namespace DriveConstants;

DriveSubsystem::DriveSubsystem()
	: m_frontLeft { kLeftMotorPorts[0] }
	, m_rearLeft { kLeftMotorPorts[1] }
	, m_frontRight { kRightMotorPorts[0] }
	, m_rearRight { kRightMotorPorts[1] } { }


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
void DriveSubsystem::MecanumDrive(double speedV, double speedH, double rotation) {
	m_frontRight.Set(rotation + (-speedV - speedH));
	m_rearRight.Set(rotation + (-speedV + speedH));
	m_frontLeft.Set(rotation + (speedV - speedH));
	m_rearLeft.Set(rotation + (speedV + speedH));
}

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
 */
void DriveSubsystem::MecanumTankDrive(double leftSpeedV, double leftSpeedH, double rightSpeedV, double rightSpeedH) {
	m_frontRight.Set(-rightSpeedV + rightSpeedH);
	m_rearRight.Set(-rightSpeedV - rightSpeedH);
	m_frontLeft.Set(leftSpeedV + leftSpeedH);
	m_rearLeft.Set(leftSpeedV - leftSpeedH);
}
