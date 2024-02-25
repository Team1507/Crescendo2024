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

    m_leftClimbMotor.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    m_rightClimbMotor.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

    //Set Follower
    m_rightClimbMotor.Follow(m_leftClimbMotor,true);

    //Limit Switches?
    m_forwardLimit.EnableLimitSwitch(true);
    m_reverseLimit.EnableLimitSwitch(true);

    
    ClimberSetPower(0);
}

void Climber::ClimberSetPower(double power)
{
    m_leftClimbMotor.Set(power);
    //m_rightClimbMotor.Set(power);//Following Left
}

void Climber::ClimberBrakeEngage(void) 
{

    m_climbBrake.Set(frc::DoubleSolenoid::kForward);
    m_isClimberBrakeActivated = true;

    ClimberSetPower(0.0); //Safety - Motors OFF when brake set
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
    return false;
    //m_forwardLimit.Get()
}

bool Climber::IsClimberBotLimitSwitch(void)
{
    return false;
    //m_reverseLimit.Get();
}

void Climber::Periodic()
{
  frc::SmartDashboard::PutBoolean("TopClimberLimitSwitch", Climber::IsClimberTopLimitSwitch());
  frc::SmartDashboard::PutBoolean("BotClimberLimitSwitch", Climber::IsClimberBotLimitSwitch());
}
