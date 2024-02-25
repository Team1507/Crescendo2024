#include "subsystems/Shooter.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

#define FEEDER_POWER 0


typedef struct 
{
   float distance;
   float velocity;
   float angle;
} shooterTable_t;


shooterTable_t shooterTable[] = 
{
   {10,20,30},
   {40,50,60},
   {70,80,90}
};


#define SHOOTER_TABLE_SIZE sizeof(shooterTable)/sizeof(shooterTable_t)



Shooter::Shooter()
{

}

void Shooter::ShooterInit()
{
   m_shooterPivot.RestoreFactoryDefaults();
   m_shooterUpper.RestoreFactoryDefaults();
   m_shooterLower.RestoreFactoryDefaults();

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

   // m_shooterPivotPID.SetP(0.0);
   // m_shooterPivotPID.SetI(0.0);
   // m_shooterPivotPID.SetD(0.0);
   // m_shooterPivotPID.SetSmartMotionAllowedClosedLoopError(0.0);
   // m_shooterPivotPID.SetOutputRange(-0.3,0.3,0);

   m_shooterLower.SetClosedLoopRampRate(0.0);
   m_shooterLower.SetInverted(false);

   m_shooterUpper.SetClosedLoopRampRate(0.0);
   m_shooterUpper.SetInverted(false);

   m_shooterPivot.SetClosedLoopRampRate(0.0);
   m_shooterPivot.SetInverted(false);

   frc::SmartDashboard::PutNumber("FEEDER_SHOOTER_POWER",FEEDER_SHOOTER_POWER);
   frc::SmartDashboard::PutNumber("FEEDER_INTAKE_POWER",FEEDER_INTAKE_POWER);

   frc::SmartDashboard::PutNumber("SHOOTER_POWER",0.0);
   frc::SmartDashboard::PutNumber("SHOOTER_RPM",0.0);

   m_feederTOF.SetRangingMode(frc::TimeOfFlight::RangingMode::kShort, 50.0);  //Max 24ms sample rate per datasheet
   m_feederTOF.SetRangeOfInterest(8,8,12,12);   //Use center 4 pixels for FOV
}

void Shooter::ShooterInterpolate(double distance)
{
   for(unsigned int i=0; i<SHOOTER_TABLE_SIZE; i++)
   { 
      if(distance < shooterTable[i].distance)
      {
         double x2 = shooterTable[i+1].distance;
         double x1 = shooterTable[i].distance;
         double y2 = shooterTable[i+1].velocity;
         double y1 = shooterTable[i].velocity;
         
         double shooterVelocity =y1 + (distance - x1)*((y2-y1) / (x2-x1));
         std::cout<<"interpolation shooter Velocity="<< shooterVelocity<<std::endl;
         SetShooterRPM(shooterVelocity);


         y2 = shooterTable[i+1].angle;
         y1 = shooterTable[i].angle;

         double shooterAngle = y1 + (distance - x1)*((y2-y1) / (x2-x1));
         std::cout<<"Interpolation Shooter Angle="<< shooterAngle<<std::endl;
         SetPivotAngle(shooterAngle);

         return;
      }
   }
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
   double testRPM = frc::SmartDashboard::GetNumber("SHOOTER_RPM",0.0);

    m_shooterUpperPID.SetReference(testRPM, rev::CANSparkMax::ControlType::kVelocity);
    m_shooterLowerPID.SetReference(testRPM, rev::CANSparkMax::ControlType::kVelocity);
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


//***********PIVOT*********************

float Shooter::Deg2Rot(float deg)
{
   return deg * DEG_PER_ROT;
} 

float Shooter::Rot2Deg(float rot)
{
   return rot / DEG_PER_ROT;
}

void Shooter::SetPivotPower(double power)
{
   m_shooterPivot.Set(power);
}

void Shooter::ResetPivotEncoder(float angle)
{
   m_shooterPivotEncoder.SetPosition( Deg2Rot(angle) );
}

double Shooter::GetPivotAngle(void)
{
   return Rot2Deg(m_shooterPivotEncoder.GetPosition());
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

void Shooter::SetPivotAngle(float position)
{
   m_shooterPivotPID.SetReference(Deg2Rot(position),rev::CANSparkMax::ControlType::kPosition);
}

void Shooter::SetFeederShooterPower(double power)
{
   m_feederMotor.Set( frc::SmartDashboard::GetNumber("FEEDER_SHOOTER_POWER",FEEDER_SHOOTER_POWER) );
}

double Shooter::GetFeederShooterPower(void)
{
   return m_feederMotor.Get();
}

void Shooter::SetFeederIntakePower(double power)
{
   m_feederMotor.Set( frc::SmartDashboard::GetNumber("FEEDER_INTAKE_POWER",FEEDER_INTAKE_POWER) );
}

double Shooter::GetFeederIntakePower(void)
{
   return m_feederMotor.Get();
}

bool Shooter::GetFeederTOF(void)
{
   if( m_feederTOF.GetRange() < 75.0 ) return true; 
   else return false;
}


// This method will be called once per scheduler run
void Shooter::Periodic() 
{
   frc::SmartDashboard::PutBoolean("FEEDER TOF", GetFeederTOF());
}
