#include "subsystems/DriverFeedback.h"
#include "Robot.h"

#define LEDDIV 10

DriverFeedback::DriverFeedback() 
{
    ctre::phoenix::led::CANdleConfiguration candleConfig {};
    //candleConfig.statusLedOffWhenActive = true;
    candleConfig.disableWhenLOS = false;    //<<<<< IF True = MUST constantly update LEDs or they turn off

    candleConfig.brightnessScalar = 1.0;

    candleConfig.stripType = LEDStripType::GRB;


   // candleConfig.vBatOutputMode = ctre::phoenix::led::VBatOutputMode::Modulated;
    m_frontCandle.ConfigAllSettings(candleConfig, 100);
    m_rearCandle.ConfigAllSettings(candleConfig, 100);


    m_blinkEnable = false;
    m_blink_count = 0;
    m_blink_r = 0;
    m_blink_g = 0;
    m_blink_b = 0;
    m_pulseCount  = 0;

    m_prevFeederNote = false;


}

void DriverFeedback::RumbleBot(float power) 
{
    robotContainer.m_botDriver.SetRumble(frc::GenericHID::RumbleType::kBothRumble,power);
}

void DriverFeedback::RumbleTop(float power) 
{
    robotContainer.m_topDriver.SetRumble(frc::GenericHID::RumbleType::kBothRumble,power);
}

void DriverFeedback::PanelLED(int r, int g, int b)
{
    m_frontCandle.SetLEDs(r,g,b,  0, 8, 11);
    m_rearCandle.SetLEDs( r,g,b,  0, 8, 11);  
}


void DriverFeedback::FeedbackLED(int r, int g, int b)
{
    m_frontCandle.SetLEDs(r/LEDDIV, g/LEDDIV, b/LEDDIV,  0, 0, 8);
    m_rearCandle.SetLEDs( r/LEDDIV, g/LEDDIV, b/LEDDIV,  0, 0, 8);
}

void DriverFeedback::BlinkLED(int r, int g, int b)
{
    m_blinkEnable = true;
    m_blink_r     = r;
    m_blink_g     = g;
    m_blink_b     = b;
    
}
void DriverFeedback::DisableBlink(void)
{
    m_blinkEnable = false;
}


void DriverFeedback::Periodic() 
{

    //--Pulse--
    if( m_pulseCount > 0)
    {
        m_pulseCount--;
        if(m_pulseCount == 0 )
            FeedbackLED(COLOR_BLACK);
        return;
    }

    //--Blink--
    const int blinkPeriod = 20;
    m_blink_count++;
    
    if( m_blinkEnable && m_blink_count == blinkPeriod/2 )
        FeedbackLED(m_blink_r,m_blink_g,m_blink_b);
    if( m_blinkEnable && m_blink_count == blinkPeriod   )
        FeedbackLED(0,0,0);
    if( m_blink_count>=blinkPeriod )
        m_blink_count = 0;


    //--Pulse--
    bool currFeederNote = robotContainer.m_shooter.GetFeederPhotoeye();

    if( currFeederNote != m_prevFeederNote )
    {
        if( currFeederNote )
        {
            m_pulseCount = 50;
            FeedbackLED(COLOR_WHITE);
        }
        m_prevFeederNote = currFeederNote;
        return;
    }



    //--LED Logic--

    if( robotContainer.m_intake.IntakeIsDeployed() )
    {
        FeedbackLED(COLOR_RED);
        m_blink_count=0;
        m_blinkEnable=false;
    }
    else
    if( robotContainer.m_photonvision.IsTargetValidAndInRange() && fabs( robotContainer.m_photonvision.GetTargetYaw() ) < 1.5 )
    {
        FeedbackLED(COLOR_GREEN);
    }
    else
    if( robotContainer.m_photonvision.IsTargetValidAndInRange() )
    {
        FeedbackLED(COLOR_YELLOW);
    }
    else
    {
        //Turn LED OFF
        if( !m_blinkEnable )
            FeedbackLED(COLOR_BLACK);
    }



    //Rumble
    if( robotContainer.m_shooter.GetFeederPhotoeye() && robotContainer.m_topDriver.GetRightBumper()  )
    {
        RumbleTop(1.0);
        RumbleBot(1.0);
    }
    else
    {
        RumbleTop(0.0);
        RumbleBot(0.0);
    }



    



}
