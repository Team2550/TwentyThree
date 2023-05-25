#include "subsystems/DriveSubsystem.h"

using namespace DriveConstants;

DriveSubsystem::DriveSubsystem()
	: m_frontLeft { kLeftMotorPorts[0] }
	, m_rearLeft { kLeftMotorPorts[1] }
	, m_frontRight { kRightMotorPorts[0] }
	, m_rearRight { kRightMotorPorts[1] } 
	, m_leftEncoder { kLeftEncoderPorts[0], kLeftEncoderPorts[1], frc::Encoder::EncodingType::k2X }
	, m_rightEncoder { kRightEncoderPorts[0], kRightEncoderPorts[1], frc::Encoder::EncodingType::k2X }
	, m_imu {} {
	// Set the distance per pulse for the encoders
	m_leftEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);
	m_rightEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);

	// Set the default yaw axis of the accelerometer to Y
	this->SetYawAxis(frc::ADIS16470_IMU::IMUAxis::kY);
}

/*
 * Drive functions
 */
void DriveSubsystem::ArcadeDrive(double speed, double rotation) { m_drive.ArcadeDrive(rotation, speed); }

void DriveSubsystem::TankDrive(double leftSpeed, double rightSpeed) { m_drive.TankDrive(-leftSpeed, rightSpeed); }

void DriveSubsystem::MecanumDrive(double speedV, double speedH, double rotation) {
	m_frontRight.Set(rotation + (-speedV - speedH));
	m_rearRight.Set(rotation + (-speedV + speedH));
	m_frontLeft.Set(rotation + (speedV - speedH));
	m_rearLeft.Set(rotation + (speedV + speedH));
}

void DriveSubsystem::MecanumTankDrive(double leftSpeedV, double leftSpeedH, double rightSpeedV, double rightSpeedH) {
	m_frontRight.Set(-rightSpeedV + rightSpeedH);
	m_rearRight.Set(-rightSpeedV - rightSpeedH);
	m_frontLeft.Set(leftSpeedV + leftSpeedH);
	m_rearLeft.Set(leftSpeedV - leftSpeedH);
}

/*
 * Encoder functions
 */
void DriveSubsystem::ResetEncoders() {
	m_leftEncoder.Reset();
	m_rightEncoder.Reset();
}

frc::Encoder& DriveSubsystem::GetLeftEncoder() { return m_leftEncoder; }

frc::Encoder& DriveSubsystem::GetRightEncoder() { return m_rightEncoder; }

double DriveSubsystem::GetAverageEncoderDistance() {
	return (std::abs(m_leftEncoder.GetDistance()) + std::abs(m_rightEncoder.GetDistance())) / 2.0;
}

/*
 * IMU functions
 */
void DriveSubsystem::ResetGyro() { m_imu.Reset(); }

void DriveSubsystem::SetYawAxis(frc::ADIS16470_IMU::IMUAxis imuAxis) { m_imu.SetYawAxis(imuAxis); }

units::angle::degree_t DriveSubsystem::GetCurrentAngle() { return m_imu.GetAngle(); }
