#include "commands/BalanceAuto.h"

BalanceAuto::BalanceAuto(units::second_t time, double speed, DriveSubsystem* subsystem)
	: m_drive(subsystem), m_time(time), m_speed(speed) {
	AddRequirements({subsystem});
}

void BalanceAuto::Initialize() {
	m_drive->ResetEncoders();
	m_drive->ArcadeDrive(m_speed, 0.5);
	m_isFinished = true;
}

void BalanceAuto::Execute() { m_drive->ArcadeDrive(m_speed, 0); }

void BalanceAuto::End(bool interrupted) { m_drive->ArcadeDrive(0, 0); }

bool BalanceAuto::IsFinished() { return m_isFinished; }