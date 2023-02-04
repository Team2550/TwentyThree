#include "commands/DriveForward.h"

DriveForward::DriveForward(double speed, DriveSubsystem* subsystem) : m_drive(subsystem), m_speed(speed) {
	AddRequirements({subsystem});
}

DriveForward::DriveForward(double speed, double distance, DriveSubsystem* subsystem)
	: m_drive(subsystem), m_distance(distance), m_speed(speed) {
	AddRequirements({subsystem});
}

void DriveForward::Initialize() {
	m_drive->ResetEncoders();
	m_drive->ArcadeDrive(m_speed, 0);
}

void DriveForward::Execute() { m_drive->ArcadeDrive(m_speed, 0); }

void DriveForward::End(bool interrupted) { m_drive->ArcadeDrive(0, 0); }

bool DriveForward::IsFinished() {
	if (m_distance) {
		return m_drive->GetAverageEncoderDistance() >= m_distance;
	} else {
		return false;
	}
}