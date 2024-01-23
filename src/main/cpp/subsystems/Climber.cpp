#include "subsystems/Climber.h"

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
    m_isClimberBrakeActivated;
}

void Climber::Periodic() {}
