#include "commands/MoveArm.h"

MoveArm::MoveArm(double upTrigger, double downTrigger, DriveSubsystem* subsystem)
	: m_drive(subsystem)
	, downTrigger(downTrigger)
	, upTrigger(upTrigger) {
	AddRequirements({ subsystem });
}

void MoveArm::Initialize() { }

void MoveArm::Execute() {
	frc::SmartDashboard::PutNumber("UP value", (m_driverController.GetLeftTriggerAxis()));
	frc::SmartDashboard::PutNumber("DOWN value", (m_driverController.GetRightTriggerAxis()));
}

void MoveArm::End(bool interrupted) { }

bool MoveArm::IsFinished() { return false; }