#include "commands/DriveForward.h"

DriveForward::DriveForward(double speed, units::meter_t distance, DriveSubsystem* subsystem)
	: m_drive(subsystem)
	, m_distance(distance)
	, m_speed(speed) {
	AddRequirements({ subsystem });

	m_distance = distance.convert<units::inches>().value();
}

void DriveForward::Initialize() {
	m_drive->ResetEncoders();
	m_drive->SetYawAxis(frc::ADIS16470_IMU::kX);
	heading = m_drive->GetCurrentAngle().value();
}

void DriveForward::Execute() {
	frc::SmartDashboard::PutNumber("Y Axis Value", (m_drive->GetCurrentAngle().value()));
	double error = heading - m_drive->GetCurrentAngle().value();

	// double kP = ((log(m_speed) + 1) / 2);
	double kP = 0.1;

	m_drive->TankDrive(m_speed + (kP * error), m_speed - (kP * error));
}

void DriveForward::End(bool interrupted) { m_drive->TankDrive(0, 0); }

bool DriveForward::IsFinished() { return std::abs(m_drive->GetRightEncoder().GetDistance()) >= 1.0; }