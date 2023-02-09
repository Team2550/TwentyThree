#include "commands/DriveForwardTimed.h"

DriveForwardTimed::DriveForwardTimed(double speed, units::second_t time, DriveSubsystem* subsystem)
	: m_drive(subsystem), m_speed(speed) {
	AddRequirements({subsystem});
	m_time = std::chrono::system_clock::now().time_since_epoch() +
			 std::chrono::system_clock::duration(int(units::millisecond_t(time).value()));
}

void DriveForwardTimed::Initialize() {
	m_drive->ResetEncoders();
	m_drive->ArcadeDrive(m_speed, 0);
}

void DriveForwardTimed::Execute() { m_drive->ArcadeDrive(m_speed, 0); }

void DriveForwardTimed::End(bool interrupted) { m_drive->ArcadeDrive(0, 0); }

bool DriveForwardTimed::IsFinished() { return std::chrono::system_clock::now().time_since_epoch() <= m_time; }