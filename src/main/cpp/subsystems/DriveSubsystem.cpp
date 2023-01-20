#include "subsystems/DriveSubsystem.h"

using namespace DriveConstants;

DriveSubsystem::DriveSubsystem()
	: m_frontLeft{kLeftMotorPorts[0]},
	  m_rearLeft{kLeftMotorPorts[1]},
	  m_frontRight{kRightMotorPorts[0]},
	  m_rearRight{kRightMotorPorts[1]},
	  m_leftEncoder{kLeftEncoderPorts[0], kLeftEncoderPorts[1], frc::Encoder::EncodingType::k2X},
	  m_rightEncoder{kRightEncoderPorts[0], kRightEncoderPorts[1], frc::Encoder::EncodingType::k2X} {
	// Set the distance per pulse for the encoders
	m_leftEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);
	m_rightEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);
}

void DriveSubsystem::TankDrive(double leftSpeed, double rightSpeed) { m_drive.TankDrive(-leftSpeed, rightSpeed); }

void DriveSubsystem::ResetEncoders() {
	m_leftEncoder.Reset();
	m_rightEncoder.Reset();
}

frc::Encoder& DriveSubsystem::GetLeftEncoder() { return m_leftEncoder; }

frc::Encoder& DriveSubsystem::GetRightEncoder() { return m_rightEncoder; }

void DriveSubsystem::SetOutputScale(double scale) { m_drive.SetMaxOutput(scale); }