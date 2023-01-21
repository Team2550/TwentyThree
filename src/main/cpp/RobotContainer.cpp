// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() { ConfigureBindings(); }

void RobotContainer::ConfigureBindings() {
	// The default command (i.e, what we do when not running anything else.)
	m_drive.SetDefaultCommand(frc2::cmd::Run(
		[this] { m_drive.TankDrive(m_driverController.GetLeftY(), m_driverController.GetRightY()); }, {&m_drive}));

	m_driverController.X().OnTrue(frc2::cmd::Run([this] {
		units::angle::degree_t degrees = m_drive.GetCurrentAngle(frc::ADIS16470_IMU::IMUAxis::kY);
		frc::SmartDashboard::PutNumber("Y axis degrees", degrees.value());
	}));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() { return frc2::cmd::Print("No autonomous command configured"); }
