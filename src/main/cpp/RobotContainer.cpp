// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/Commands.h>
#include <frc2/command/FunctionalCommand.h>

#include "commands/BalanceAuto.h"

RobotContainer::RobotContainer() { ConfigureBindings(); }

void RobotContainer::ConfigureBindings() {
	m_drive.SetDefaultCommand(
		// The default command (i.e, what we do when not running anything else.)
		// Make sure to compensate for the controllers' inverted Y axes on the stick
		frc2::cmd::Run([this] { m_drive.ArcadeDrive(-m_driverController.GetLeftY(), m_driverController.GetRightX()); },
					   {&m_drive}));

	frc2::CommandPtr driveDashboard = m_drive.OutputToSmartDashboard().Repeatedly();
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
	BalanceAuto balanceAuto = BalanceAuto(0.3_s, 0.5, &m_drive);

	return frc2::CommandPtr(balanceAuto).AsProxy().AndThen(frc2::cmd::Print("ahoy-hoy"));
};