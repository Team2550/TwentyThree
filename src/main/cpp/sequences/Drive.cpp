#include "sequences/Drive.h"

Drive::Drive(DriveSubsystem* subsystem)
	: m_drive(subsystem) {
	AddRequirements({ subsystem });
}

void Drive::Initialize() { m_speedMult = 0.75; }

void Drive::Execute() {
	if (m_driverController.GetRightBumper() == 1) {
		frc::SmartDashboard::PutString("Turbo status:", "✅");
		m_drive->ArcadeDrive(((m_driverController.GetLeftY())), ((-m_driverController.GetRightX())));
	} else {
		frc::SmartDashboard::PutString("Turbo status:", "❌");
		m_drive->ArcadeDrive(
			((m_driverController.GetLeftY()) * m_speedMult), ((-m_driverController.GetRightX()) * m_speedMult));
	}

	frc::SmartDashboard::PutNumber("Forward speed:", -m_driverController.GetLeftY());
	frc::SmartDashboard::PutNumber("Turning speed:", -m_driverController.GetRightX());

	if (m_armController.GetLeftTriggerAxis() < m_armController.GetRightTriggerAxis()) {
		m_drive->MoveArm(-m_armController.GetRightTriggerAxis());
		frc::SmartDashboard::PutString("Arm status:", "MOVING UP");
	} else {
		if (m_armController.GetLeftTriggerAxis() > m_armController.GetRightTriggerAxis()) {
			m_drive->MoveArm(m_armController.GetLeftTriggerAxis());
			frc::SmartDashboard::PutString("Arm status:", "MOVING DOWN");
		};
	}
	if (m_armController.GetLeftTriggerAxis() == m_armController.GetRightTriggerAxis()) {
		m_drive->MoveArm(0.0);
		frc::SmartDashboard::PutString("Arm status:", "NOT MOVING");
	}

	if (m_driverController.GetAButton() == 1 && m_driverController.GetBButton() == 1) {
	} else if (m_driverController.GetAButton() == 1) {
		m_drive->DriveWinch(-0.5);
	} else if (m_driverController.GetBButton() == 1) {
		m_drive->DriveWinch(0.5);
	}

	if (m_armController.GetAButton() == 1 && m_armController.GetBButton() == 0) {
		m_drive->ArmRelease();
	}
	if (m_armController.GetBButton() == 1 && m_armController.GetAButton() == 0) {
		m_drive->ArmGrab();
	}
	if (m_armController.GetBButton() == 0 && m_armController.GetAButton() == 0) {
		m_drive->ArmRest();
	}
}

void Drive::End(bool interrupted) { }

bool Drive::IsFinished() { return false; }