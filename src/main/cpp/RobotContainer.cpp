// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <frc2/command/ParallelCommandGroup.h>

RobotContainer::RobotContainer() { ConfigureBindings(); }

void RobotContainer::ConfigureBindings() {
	m_drive.SetDefaultCommand(ArcadeDrive(&m_drive).ToPtr());
	ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
	m_driverController.A().OnTrue(ArmHand(ArmHand::Value::kGrab, &m_drive).ToPtr());
	m_driverController.B().OnTrue(ArmHand(ArmHand::Value::kRelease, &m_drive).ToPtr());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() { return frc2::CommandPtr(BalanceAuto(&m_drive)); };

frc2::CommandPtr RobotContainer::GetTestCommand() {
	return frc2::CommandPtr(ArmHand(ArmHand::Value::kGrab, &m_drive).ToPtr());
};