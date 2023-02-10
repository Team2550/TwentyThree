#include "commands/DriveForwardTimed.h"

DriveForwardTimed::DriveForwardTimed(double speed, units::second_t time, DriveSubsystem* subsystem)
	: m_drive(subsystem), m_speed(speed) {
	AddRequirements({subsystem});
	m_desiredMs = int(units::millisecond_t(time).value());
}

void DriveForwardTimed::Initialize() {
	m_drive->ResetEncoders();
	heading = m_drive->GetCurrentAngle().value();
}

void DriveForwardTimed::Execute() {
	frc::SmartDashboard::PutNumber("Y Axis Value", (m_drive->GetCurrentAngle().value()));
	double error = heading - m_drive->GetCurrentAngle().value();

	m_drive->TankDrive(m_speed + kP * error, m_speed - kP * error);
	m_msOccurred += 20;
}

void DriveForwardTimed::End(bool interrupted) { m_drive->TankDrive(0, 0); }

bool DriveForwardTimed::IsFinished() { return m_msOccurred >= m_desiredMs; }