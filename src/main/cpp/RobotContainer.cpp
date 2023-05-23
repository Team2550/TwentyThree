// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() { ConfigureBindings(); }

void RobotContainer::ConfigureBindings() {
	m_drive.SetDefaultCommand(Drive(&m_drive).ToPtr());
	ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() { }

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {};

frc2::CommandPtr RobotContainer::GetTestCommand() {};