#include "subsystems/DriverFeedback.h"
#include "Robot.h"

DriverFeedback::DriverFeedback() 
{
    ctre::phoenix::led::CANdleConfiguration candleConfig {};
    //candleConfig.statusLedOffWhenActive = true;
    candleConfig.disableWhenLOS = false;    //<<<<< IF True = MUST constantly update LEDs or they turn off

    candleConfig.brightnessScalar = 0.05;
   // candleConfig.vBatOutputMode = ctre::phoenix::led::VBatOutputMode::Modulated;
    m_frontCandle.ConfigAllSettings(candleConfig, 100);
    m_rearCandle.ConfigAllSettings(candleConfig, 100);


}

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
    m_frontCandle.SetLEDs(r,g,b);
    m_rearCandle.SetLEDs(r,g,b);
}

void DriverFeedback::Periodic() {}
