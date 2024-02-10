#include "subsystems/DriverFeedback.h"
#include "Robot.h"

DriverFeedback::DriverFeedback() = default;

void DriverFeedback::RumbleBot(float power) 
{
    robotContainer.m_botDriver.SetRumble(frc::GenericHID::RumbleType::kBothRumble,power);
}

void DriverFeedback::RumbleTop(float power) 
{
    robotContainer.m_topDriver.SetRumble(frc::GenericHID::RumbleType::kBothRumble,power);
}

void DriverFeedback::FeedbackLED(int r, int g, int b)
{

}

void DriverFeedback::Periodic() {}
