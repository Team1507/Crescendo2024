#include "subsystems/Climber.h"
#include "frc/smartdashboard/SmartDashboard.h"

Climber::Climber() = default;

void Climber::ClimberInit(void) 
{
    m_climbBrake.Set(frc::DoubleSolenoid::kReverse);

    m_isClimberActivated = false;
    m_isClimberBrakeActivated = false;

    m_leftClimbMotor.RestoreFactoryDefaults();
    m_rightClimbMotor.RestoreFactoryDefaults();
    
    ClimberSetPower(0);
}

void Climber::ClimberSetPower(double power)
{
    m_leftClimbMotor.Set(power);
    m_rightClimbMotor.Set(power);
}

void Climber::ClimberBrakeEngage(void) 
{

    m_climbBrake.Set(frc::DoubleSolenoid::kForward);
    m_isClimberBrakeActivated = true;
}

void Climber::ClimberBrakeDisengage(void)
{
    m_climbBrake.Set(frc::DoubleSolenoid::kReverse);
    m_isClimberBrakeActivated = false;    
}

bool Climber::IsClimberEngaged(void)
{
    return m_isClimberActivated;
}

bool Climber::IsClimberBrakeEngaged(void)
{
   return m_isClimberBrakeActivated;
}
bool Climber::IsClimberTopLimitSwitch(void)
{
    return m_topLimitSwitch.Get();
}
bool Climber::IsClimberBotLimitSwitch(void)
{
    return m_botLimitSwitch.Get();
}

void Climber::Periodic()
{
  frc::SmartDashboard::PutBoolean("TopClimberLimitSwitch", Climber::IsClimberTopLimitSwitch());
  frc::SmartDashboard::PutBoolean("BotClimberLimitSwitch", Climber::IsClimberBotLimitSwitch());
}
