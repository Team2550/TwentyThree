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
	
	frc::Translation2d m_frontLeftLocation{0.381_m, 0.381_m};
	frc::Translation2d m_frontRightLocation{0.381_m, -0.381_m};
	frc::Translation2d m_rearLeftLocation{-0.381_m, 0.381_m};
	frc::Translation2d m_rearRightLocation{-0.381_m, -0.381_m};
}

/*
 * Drive functions
 */
void DriveSubsystem::ArcadeDrive(double speed, double rotation) { 
	// Deadzone
  	if (abs(speed) < kDeadzone) speed = 0;
	if (abs(rotation) < kDeadzone) rotation = 0;

	m_drive.ArcadeDrive(rotation, speed); 
}

void DriveSubsystem::TankDrive(double leftSpeed, double rightSpeed) {
	// Deadzone
  	if (abs(leftSpeed) < kDeadzone) leftSpeed = 0;
  	if (abs(rightSpeed) < kDeadzone) rightSpeed = 0;

	m_drive.TankDrive(-leftSpeed, rightSpeed); 
}

void DriveSubsystem::MecanumDrive(double speedV, double speedH, double rotation) {
	// Deadzone
  	if (abs(speedV) < kDeadzone) speedV = 0;
  	if (abs(speedH) < kDeadzone) speedH = 0;
	if (abs(rotation) < kDeadzone) rotation = 0;

	m_frontRight.Set(rotation + (-speedV - speedH));
	m_rearRight.Set(rotation + (-speedV + speedH));
	m_frontLeft.Set(rotation + (speedV - speedH));
	m_rearLeft.Set(rotation + (speedV + speedH));
}

void DriveSubsystem::MecanumTankDrive(double leftSpeedV, double leftSpeedH, double rightSpeedV, double rightSpeedH) {
	// Deadzone
  	if (abs(leftSpeedV) < kDeadzone) leftSpeedV = 0;
  	if (abs(leftSpeedH) < kDeadzone) leftSpeedH = 0;
	if (abs(rightSpeedV) < kDeadzone) rightSpeedV = 0;
  	if (abs(rightSpeedH) < kDeadzone) rightSpeedH = 0;


	m_frontRight.Set(-rightSpeedV + rightSpeedH);
	m_rearRight.Set(-rightSpeedV - rightSpeedH);
	m_frontLeft.Set(leftSpeedV + leftSpeedH);
	m_rearLeft.Set(leftSpeedV - leftSpeedH);
}

void Drive::initializeSwerveOdometry(frc::Rotation2d imuAngle, frc::Pose2d pose) {
  delete odometry;
  odometry = new frc::SwerveDriveOdometry<4>(m_kinematics, imuAngle, pose);
}

void DriveSubsystem::SwerveDrive(units::meters_per_second_t speedV, units::meters_per_second_t speedH, units::radians_per_second_t rotation, units::angle::degree_t imuAngle) {
	// Deadzone
  	if (abs(speedV.value()) < 0.5) speedV = units::meters_per_second_t{0};
  	if (abs(speedH.value()) < 0.5) speedH = units::meters_per_second_t{0};

	speeds = frc::ChassisSpeeds::FromFieldRelativeSpeeds(speedH, speedV, rotation, frc::Rotation2d(imuAngle));
	auto [fl, fr, bl, br] = m_kinematics.ToSwerveModuleStates(speeds);

	//REST OF CODE HERE
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
