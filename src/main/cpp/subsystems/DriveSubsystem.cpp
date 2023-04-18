#include "subsystems/DriveSubsystem.h"

using namespace DriveConstants;

DriveSubsystem::DriveSubsystem()
	: m_frontLeft { kLeftMotorPorts[0] }
	, m_rearLeft { kLeftMotorPorts[1] }
	, m_frontRight { kRightMotorPorts[0] }
	, m_rearRight { kRightMotorPorts[1] } { }

void DriveSubsystem::PolarDrive(double speed, frc::Rotation2d angle, double rotation) {
	m_drive.DrivePolar(speed, angle, rotation);
}