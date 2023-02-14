#include "commands/DriveTurn.h"

DriveTurn::DriveTurn(double speed, double turnheading, DriveSubsystem* subsystem)
	: m_drive(subsystem), m_turnheading(turnheading), m_speed(speed) {
	AddRequirements({subsystem});
}

void DriveTurn::Initialize() {
	m_drive->ResetGyro();
	m_drive->ResetEncoders();
	heading = m_drive->GetCurrentAngle().value();
}

void DriveTurn::Execute() {
	double error = m_turnheading - heading;

	double kP = 0.1;

	m_drive->TankDrive(m_speed * (kP * error), m_speed * (-kP * error));
}

void DriveTurn::End(bool interrupted) { m_drive->TankDrive(0, 0); }

// Figure out how to test if the turn is complete.
bool DriveTurn::IsFinished() {
	double currentAngle = m_drive->GetCurrentAngle().value();
	if ((currentAngle < (m_turnheading + 0.5) && (m_turnheading - 0.5) < currentAngle)) {
		return true;
	};
	return false;
}