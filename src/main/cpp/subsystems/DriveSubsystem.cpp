#include "subsystems/DriveSubsystem.h"

using namespace DriveConstants;

DriveSubsystem::DriveSubsystem()
	: m_frontLeft{kLeftMotorPorts[0]},
	  m_rearLeft{kLeftMotorPorts[1]},
	  m_frontRight{kRightMotorPorts[0]},
	  m_rearRight{kRightMotorPorts[1]},
	  m_leftEncoder{kLeftEncoderPorts[0], kLeftEncoderPorts[1], frc::Encoder::EncodingType::k2X},
	  m_rightEncoder{kRightEncoderPorts[0], kRightEncoderPorts[1], frc::Encoder::EncodingType::k2X},
	  m_imu{} {
	// Set the distance per pulse for the encoders
	m_leftEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);
	m_rightEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);

	// Set the default yaw axis of the accelerometer to Y
	this->SetYawAxis(frc::ADIS16470_IMU::IMUAxis::kY);
}

void DriveSubsystem::ArcadeDrive(double speed, double rotation) { m_drive.ArcadeDrive(-speed, rotation); }

void DriveSubsystem::ResetEncoders() {
	m_leftEncoder.Reset();
	m_rightEncoder.Reset();
}

frc::Encoder& DriveSubsystem::GetLeftEncoder() { return m_leftEncoder; }

frc::Encoder& DriveSubsystem::GetRightEncoder() { return m_rightEncoder; }

void DriveSubsystem::SetYawAxis(frc::ADIS16470_IMU::IMUAxis imuAxis) { m_imu.SetYawAxis(imuAxis); }

units::angle::degree_t DriveSubsystem::GetCurrentAngle() { return m_imu.GetAngle(); }

void DriveSubsystem::SetOutputScale(double scale) { m_drive.SetMaxOutput(scale); }

frc2::CommandPtr DriveSubsystem::OutputToSmartDashboard() {
	return this->Run([this] {
		// Get data for SmartDashboard
		units::angle::degree_t degrees = this->GetCurrentAngle();

		// Publish the SmartDashboard data
		frc::SmartDashboard::PutNumber("Y axis degrees", degrees.value());
	});
}