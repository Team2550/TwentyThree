#include "commands/BalanceAuto.h"

BalanceAuto::BalanceAuto(double inches, double speed, DriveSubsystem* subsystem)
	: m_drive(subsystem), m_distance(inches), m_speed(speed) {
	AddRequirements({subsystem});
}

void BalanceAuto::Initialize() {
	m_drive->ResetEncoders();
	m_drive->ArcadeDrive(m_speed, 0);
}

void BalanceAuto::Execute() { m_drive->ArcadeDrive(m_speed, 0); }

void BalanceAuto::End(bool interrupted) { m_drive->ArcadeDrive(0, 0); }

// Due to diffrences between the production and testing robot,
// the production robot should use GetAverageEncoderDistance()
// instead. The testing robot only has the left encoder plugged
// in so it should use GetLeftEncoder().GetDistance()

bool BalanceAuto::IsFinished() { return std::abs(m_drive->GetLeftEncoder().GetDistance()) >= m_distance; }