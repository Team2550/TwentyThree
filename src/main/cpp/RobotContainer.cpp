// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() { ConfigureBindings(); }

void RobotContainer::ConfigureBindings() {
	m_drive.SetDefaultCommand(

		// The default command (i.e, what we do when not running anything else.)
		frc2::cmd::Run([this] { m_drive.ArcadeDrive(m_driverController.GetRightX(), m_driverController.GetLeftY()); },
					   {&m_drive}));

	frc2::CommandPtr driveDashboard = m_drive.OutputToSmartDashboard().Repeatedly();
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() { return frc2::cmd::Print("No autonomous command configured"); }
