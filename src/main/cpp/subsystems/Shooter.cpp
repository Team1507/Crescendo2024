#include "subsystems/Shooter.h"
#include <frc/smartdashboard/SmartDashboard.h>

Shooter::Shooter()
{
   m_shooterLowerPID.SetP(0.0);
   m_shooterLowerPID.SetI(0.0);
   m_shooterLowerPID.SetD(0.0);
   m_shooterLowerPID.SetSmartMotionAllowedClosedLoopError(0.0);
   m_shooterLowerPID.SetOutputRange(-0.3,0.3,0);

   m_shooterUpperPID.SetP(0.0);
   m_shooterUpperPID.SetI(0.0);
   m_shooterUpperPID.SetD(0.0);
   m_shooterUpperPID.SetSmartMotionAllowedClosedLoopError(0.0);
   m_shooterUpperPID.SetOutputRange(-0.3,0.3,0);

   m_shooterPivotPID.SetP(0.0);
   m_shooterPivotPID.SetI(0.0);
   m_shooterPivotPID.SetD(0.0);
   m_shooterPivotPID.SetSmartMotionAllowedClosedLoopError(0.0);
   m_shooterPivotPID.SetOutputRange(-0.3,0.3,0);

   m_shooterLower.RestoreFactoryDefaults();
   m_shooterLower.SetClosedLoopRampRate(0.0);
   m_shooterLower.SetInverted(false);

   m_shooterUpper.RestoreFactoryDefaults();
   m_shooterUpper.SetClosedLoopRampRate(0.0);
   m_shooterUpper.SetInverted(false);

   m_shooterPivot.RestoreFactoryDefaults();
   m_shooterPivot.SetClosedLoopRampRate(0.0);
   m_shooterPivot.SetInverted(false);
}

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
   m_shooterPivotPID.SetReference(position,rev::CANSparkMax::ControlType::kPosition);
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
