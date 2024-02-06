#include "subsystems/Shooter.h"
#include <frc/smartdashboard/SmartDashboard.h>

#define FEEDER_POWER 0

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

    m_feederTimeOfFlight.SetRangingMode(frc::TimeOfFlight::RangingMode::kShort, 50.0);  //Max 24ms sample rate per datasheet
    m_feederTimeOfFlight.SetRangeOfInterest(8,8,12,12);   //Use center 4 pixels for FOV
}

void Shooter::Periodic()
{
   frc::SmartDashboard::PutBoolean("TOF: FeederIsRangeValid",  m_feederTimeOfFlight.IsRangeValid()   );
    frc::SmartDashboard::PutNumber("TOF: FeederGetRange",      m_feederTimeOfFlight.GetRange()       );
    frc::SmartDashboard::PutNumber("TOF: FeederGetStatus",     m_feederTimeOfFlight.GetStatus()      );

    //Detecting object based on range only, ignoring IsRangeValid
    bool objectDetect = false;
    if( m_feederTimeOfFlight.GetRange() < 75.0 )objectDetect = true;
    frc::SmartDashboard::PutBoolean("TOF: FeederObjectDetect",  objectDetect   );

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
   m_shooterPivotPID.SetReference(position, rev::CANSparkMax::ControlType::kPosition);
}

void Shooter::SetFeederShooterPower(double power)
{
   m_feederMotor.Set( frc::SmartDashboard::GetNumber("FEEDER_POWER",FEEDER_SHOOTER_POWER) );
}

double Shooter::GetFeederShooterPower(void)
{
   return m_feederMotor.Get();
}

void Shooter::SetFeederIntakePower(double power)
{
   m_feederMotor.Set( frc::SmartDashboard::GetNumber("FEEDER_POWER",FEEDER_INTAKE_POWER) );
}

double Shooter::GetFeederIntakePower(void)
{
   return m_feederMotor.Get();
}

bool Shooter::GetFeederStatus(void)
{
   return m_feederStatus;
}

bool Shooter::FeederInRange(void)
{
   return m_feederTimeOfFlight.IsRangeValid();
}



