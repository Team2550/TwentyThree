#include "subsystems/DriveSubsystem.h"

using namespace DriveConstants;

DriveSubsystem::DriveSubsystem()
	: m_frontLeft { kLeftMotorPorts[0] }
	, m_rearLeft { kLeftMotorPorts[1] }
	, m_frontRight { kRightMotorPorts[0] }
	, m_rearRight { kRightMotorPorts[1] } { }


/*
* Note to self:
*
* Xbox controllers are weird, when testing,
* make sure the stick isn't inverted or something.
* try not to tear the robot in halfs.
*
* - G
*
*/
void DriveSubsystem::MecanumDrive(double speedV, double speedH, double rotation) {
	m_frontRight.Set(rotation + (speedV + speedH));
	m_rearRight.Set(rotation + (speedV - speedH));
	m_frontLeft.Set(rotation + (speedV - speedH));
	m_rearLeft.Set(rotation + (speedV + speedH));
}