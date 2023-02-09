#include "commands/DriveForwardTimed.h"

DriveForwardTimed::DriveForwardTimed(double speed, units::second_t time, DriveSubsystem* subsystem)
	: m_drive(subsystem), m_speed(speed) {
	AddRequirements({subsystem});
	m_desiredMs = int(units::millisecond_t(time).value());
}

void DriveForwardTimed::Initialize() {
	m_drive->ResetEncoders();
}

void DriveForwardTimed::Execute() { 
	m_drive->ArcadeDrive(m_speed, 0);
	m_msOccurred += 20;
}

void DriveForwardTimed::End(bool interrupted) { m_drive->ArcadeDrive(0, 0); }

bool DriveForwardTimed::IsFinished() { return m_msOccurred >= m_desiredMs; }