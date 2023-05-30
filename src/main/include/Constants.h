// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <units/angle.h>
#include <units/angular_velocity.h>
#include <units/time.h>
#include <units/voltage.h>
#include <units/meters.h>

#include <numbers>

/**
 * @brief Contains motor port and encoder port values, along with motor locations for swerve
 */
namespace DriveConstants {
constexpr int kLeftMotorPorts[] = { 0, 1 };
constexpr int kRightMotorPorts[] = { 2, 3 };

constexpr int kLeftEncoderPorts[] = { 0, 1 };
constexpr int kRightEncoderPorts[] = { 2, 3 };
constexpr bool kLeftEncoderReversed = false;
constexpr bool kRightEncoderReversed = true;

// Wont work 
constexpr frc::Translation2d kFrontLeftLocation{0.381_m, 0.381_m};
constexpr frc::Translation2d kFrontRightLocation{0.381_m, -0.381_m};
constexpr frc::Translation2d kBackLeftLocation{-0.381_m, 0.381_m};
constexpr frc::Translation2d kBackRightLocation{-0.381_m, -0.381_m};

} // namespace DriveConstants

/**
 * @brief Contains the length of time for auto
 */
namespace AutoConstants {
constexpr auto kAutoTimeoutSeconds = 12_s;
constexpr auto kAutoShootTimeSeconds = 7_s;
} // namespace AutoConstants

/**
 * @brief Contains the ports used for controlers
 */
namespace OIConstants {
constexpr int kDriverControllerPort = 0;
} // namespace OIConstants
