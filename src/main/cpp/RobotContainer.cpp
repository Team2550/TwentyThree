// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() { ConfigureBindings(); }

void RobotContainer::ConfigureBindings() {
	m_drive.SetDefaultCommand(
		// The default command (i.e, what we do when not running anything else.)
		// Make sure to compensate for the controllers' inverted Y axes on the stick

		frc2::RunCommand(
			[this] { m_drive.ArcadeDrive(-m_driverController.GetLeftY(), m_driverController.GetRightX()); },
			{ &m_drive }));

	// Left this in for testing reasons, why is everything backwards when compared to Arcade???
	// What is this horrible-ness????

	/*
	frc2::cmd::Run([this] { m_drive.TankDrive(m_driverController.GetRightY(), m_driverController.GetLeftY()); },
				   {&m_drive}));
	*/
	ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {

	frc2::JoystickButton(&m_driverController, frc::XboxController::Button::kRightBumper)
		.WhileTrue(MoveArm(m_driverController.GetLeftTriggerAxis(), m_driverController.GetRightTriggerAxis(), &m_drive)
					   .ToPtr());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() { return frc2::CommandPtr(BalanceAuto(&m_drive)); };
