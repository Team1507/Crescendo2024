#include "subsystems/Shooter.h"

Shooter::Shooter() = default;

void Shooter::ShooterInit()
{

}

//*************SHOOTER****************

void Shooter::SetShooterPower(double power) 
{
    m_shooterUpper.Set(power);
    m_shooterLower.Set(power);
}

void Shooter::SetShooterRPM(double rpm)
{
    m_shooterUpperPID.SetReference(rpm, rev::CANSparkMax::ControlType::kVelocity);
    m_shooterLowerPID.SetReference(rpm, rev::CANSparkMax::ControlType::kVelocity);
}

void Shooter::SetIdle(bool idle)
{

}

double Shooter::GetUpperShooterPower(void)
{
   return m_shooterUpper.Get();
}

double Shooter::GetLowerShooterPower(void)
{
   return m_shooterLower.Get();
}


double Shooter::GetUpperShooterRPM(void)
{
   return m_shooterUpperEncoder.GetVelocity();
}

double Shooter::GetLowerShooterRPM(void)
{
   return m_shooterLowerEncoder.GetVelocity();
}

bool Shooter::IsIdle(void)
{
   return m_isIdle;
}

//***********PIVOT*********************

void Shooter::SetPivotAngle(double angle)
{
   m_shooterPivotEncoder.SetPosition(angle);
}

void Shooter::SetPivotPower(double power)
{
   m_shooterPivot.Set(power);
}

void Shooter::ResetPivotEncoder(void)
{
   m_shooterPivotEncoder.SetPosition(0);
}

double Shooter::GetPivotAngle(void)
{
   return  m_shooterPivotEncoder.GetPosition();
}

double Shooter::GetPivotPower(void)
{
   return m_shooterPivot.Get();
}

bool Shooter::GetUpperPivotLimitSW(void)
{
   return 0;
}

bool Shooter::GetLowerPivotLimitSW(void)
{
   return 0;
}



// This method will be called once per scheduler run
void Shooter::Periodic() {}
