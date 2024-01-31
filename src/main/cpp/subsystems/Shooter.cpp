#include "subsystems/Shooter.h"
#include <frc/smartdashboard/SmartDashboard.h>

Shooter::Shooter() = default;

void Shooter::ShooterInit()
{

}

void Shooter::ShooterInterpolate(double distance)
{
   
}

//*************SHOOTER****************

void Shooter::SetShooterPower(double power) 
{
   double testPower = frc::SmartDashboard::GetNumber("SHOOTER_POWER",0.0);

    m_shooterUpper.Set(testPower);
    m_shooterLower.Set(testPower);
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
   return m_shooterPivotFwLimit.Get();
}

bool Shooter::GetLowerPivotLimitSW(void)
{
   return m_shooterPivotRvLimit.Get();
}

void Shooter::HoldPivotAngle(float position)
{
   return;
}

void Shooter::SetFeederPower(double power)
{
   m_feederMotor.Set(power);
}

double Shooter::GetFeederPower(void)
{
   return m_feederMotor.Get();
}

bool Shooter::GetFeederStatus(void)
{
   return m_feederStatus;
}

bool Shooter::GetFeederPhotoEye(void)
{
   return m_feederPhotoEye.Get();
}


// This method will be called once per scheduler run
void Shooter::Periodic() 
{
   
}
