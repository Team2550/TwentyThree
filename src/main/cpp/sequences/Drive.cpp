#include "sequences/Drive.h"

Drive::Drive(DriveSubsystem* subsystem)
	: m_drive(subsystem) {
	AddRequirements({ subsystem });
}

void Drive::Initialize() { m_speedMult = 0.70; }

void Drive::Execute() {
	// Smartdashboard outputs for controls
	frc::SmartDashboard::PutNumber("Forward speed:", -m_driverController.GetLeftY());
	frc::SmartDashboard::PutNumber("Turning speed:", -m_driverController.GetRightX());

	// Movement + Turbo toggle
	if (m_driverController.GetRightBumper() == 1) {
		frc::SmartDashboard::PutString("Turbo status:", "✅");
		m_drive->PolarDrive(((m_driverController.GetLeftY())), frc::Rotation2d(), ((m_driverController.GetRightX())));
	} else {
		frc::SmartDashboard::PutString("Turbo status:", "❌");
		m_drive->PolarDrive(((m_driverController.GetLeftY()) * m_speedMult), frc::Rotation2d(),
			((m_driverController.GetRightX()) * m_speedMult));
	}
}

void Drive::End(bool interrupted) { }

bool Drive::IsFinished() { return false; }