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
   m_shooterPivot.RestoreFactoryDefaults();
   m_shooterUpper.RestoreFactoryDefaults();
   m_shooterLower.RestoreFactoryDefaults();
   m_feederMotor. RestoreFactoryDefaults();
}

void Shooter::ShooterInit()
{
   m_feederMotor.SetInverted(true);
   m_feederMotor.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
   m_forwardLimit.EnableLimitSwitch(false);

   m_shooterLowerPID.SetP(0.0);
   m_shooterLowerPID.SetI(0.0);
   m_shooterLowerPID.SetD(0.0);
   m_shooterLowerPID.SetOutputRange(-0.3,0.3,0);


   m_shooterUpperPID.SetP(0.0);
   m_shooterUpperPID.SetI(0.0);
   m_shooterUpperPID.SetD(0.0);
   m_shooterUpperPID.SetOutputRange(-0.3,0.3,0);

   m_shooterPivotPID.SetP(2.0);   // .1 rotation = .2 power 
   m_shooterPivotPID.SetI(0.0);
   m_shooterPivotPID.SetD(0.0);
   m_shooterPivotPID.SetOutputRange(-0.6, 0.6 ,0);
   m_shooterPivotPID.SetFeedbackDevice(m_shooterPivotEncoder);

   m_shooterLower.SetClosedLoopRampRate(0.0);
   m_shooterLower.SetInverted(true);

   m_shooterUpper.SetClosedLoopRampRate(0.0);
   m_shooterUpper.SetInverted(false);

   m_shooterPivot.SetClosedLoopRampRate(0.0);
   m_shooterPivot.SetInverted(true);
   m_shooterPivotBotLimit.EnableLimitSwitch(true);

   m_startingPivotAngle   = 50;
   m_startingPivotEncoder = 0;

   frc::SmartDashboard::PutNumber("FEEDER_SHOOTER_POWER",FEEDER_SHOOTER_POWER);
   frc::SmartDashboard::PutNumber("FEEDER_INTAKE_POWER",FEEDER_INTAKE_POWER);

   frc::SmartDashboard::PutNumber("SHOOTER_POWER",0.0);
   frc::SmartDashboard::PutNumber("SHOOTER_RPM",0.0);

   // m_feederTOF.SetRangingMode(frc::TimeOfFlight::RangingMode::kShort, 50.0);  //Max 24ms sample rate per datasheet
   // m_feederTOF.SetRangeOfInterest(8,8,12,12);   //Use center 4 pixels for FOV
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
    m_shooterUpper.Set(power);
    m_shooterLower.Set(power);
}

void Shooter::SetShooterPowerDB(void)
{
   m_shooterUpper.Set(frc::SmartDashboard::GetNumber("SHOOTER_POWER",FEEDER_SHOOTER_POWER));
   m_shooterLower.Set(frc::SmartDashboard::GetNumber("SHOOTER_POWER",FEEDER_SHOOTER_POWER));
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
   return ( (deg - m_startingPivotAngle) / DEG_PER_ROT) + m_startingPivotEncoder;
} 

float Shooter::Rot2Deg(float rot)
{
   return ( (rot - m_startingPivotEncoder) * DEG_PER_ROT) + m_startingPivotAngle;
}

float Shooter::Pot2Deg(void)
{
   //y=mx+b;
   const float m = 22.559;   //Calc from pot Calibration
   const float b = 2633.36;

   return ( m_pivotAnglePot.GetValue() -b ) / m;
}

void Shooter:: SetPivotEncoderCal(void)
{
   //Cal Pivot encoder from Pot value
   std::cout << "Pivot Pot Cal = " << Pot2Deg() << std::endl;


   //Store known starting angle (from POT voltage) -and- starting SparkMax encoder value
   //  Aligning these values allows us to use pid encoder to control pivot angle
   //   Note: For some reson, SparkMax will not reset encoder value, so we need to store.
   m_startingPivotAngle   = Pot2Deg();
   m_startingPivotEncoder = GetPivotEncoder();

}

bool Shooter::CheckPotVsRotAngle(void)
{
   //Compare pot to Encoder pivot angle and return if out of spec
   const float maxDelta = 1.0;
   return   fabs( Rot2Deg(GetPivotEncoder()) - Pot2Deg() ) <= maxDelta;
}


void Shooter::SetPivotPower(double power)
{
   m_shooterPivot.Set(power);
}

void Shooter::ResetPivotEncoder(float angle)
{
   //Disable for now...
   //m_shooterPivotEncoder.SetPosition( Deg2Rot(angle) );
}

double Shooter::GetPivotAngle(void)
{
   return Rot2Deg(m_shooterPivotEncoder.GetPosition());
}

double Shooter::GetPivotEncoder(void)
{
   return m_shooterPivotEncoder.GetPosition();
}


double Shooter::GetPivotPower(void)
{
   return m_shooterPivot.Get();
}


void Shooter::SetPivotAngle(float position)
{
   m_shooterPivotPID.SetReference(Deg2Rot(position),rev::CANSparkMax::ControlType::kPosition);
}

bool Shooter::GetPivotBotLimit(void)
{
   //return m_shooterPivotBotLimit.Get();
   return m_pivotBotLimitSw.Get();
}


void Shooter::SetFeederShooterPower(double power)
{
   if (power == 0)
   {
      m_feederMotor.Set(0);
   }
   else
{
   m_feederMotor.Set( frc::SmartDashboard::GetNumber("FEEDER_SHOOTER_POWER",FEEDER_SHOOTER_POWER) );
}
}

double Shooter::GetFeederShooterPower(void)
{
   return m_feederMotor.Get();
}

void Shooter::SetFeederIntakePower(double power)
{
   if(power == 0)
   {
      m_feederMotor.Set(0);
   
   }
   else if (power < 0)
   {
      m_feederMotor.Set(power);
   }
   else
   {
      m_feederMotor.Set( frc::SmartDashboard::GetNumber("FEEDER_INTAKE_POWER",FEEDER_INTAKE_POWER) );
   }
}

double Shooter::GetFeederIntakePower(void)
{
   return m_feederMotor.Get();
}

// bool Shooter::GetFeederTOFDetect(void)
// {
//    if( m_feederTOF.GetRange() < 110.0 ) return true; 
//    else return false;
// }

// float  Shooter::GetFeederTOFRange(void)
// {
//    return m_feederTOF.GetRange();
// }

bool Shooter::GetFeederPhotoeye(void)
{
  return m_feederPhotoeye.Get();
}

// bool Shooter::GetFeederPhotoeye2(void)
// {
//    return m_feederPhotoeye.Get();
// }



// This method will be called once per scheduler run
void Shooter::Periodic() 
{
   frc::SmartDashboard::PutBoolean ("FEEDER PHOTOEYE DETECT", GetFeederPhotoeye());
   // frc::SmartDashboard::PutBoolean ("***FEEDER PHOTOEYE 2***", GetFeederPhotoeye2());
   frc::SmartDashboard::PutBoolean ("Pivot Bot Sw", GetPivotBotLimit() );
  
   // frc::SmartDashboard::PutBoolean ("FEEDER TOF DETECT", GetFeederTOFDetect());
   // frc::SmartDashboard::PutNumber  ("FEEDER TOF RANGE", GetFeederTOFRange());

   // frc::SmartDashboard::PutNumber  ("Pivot Encoder", GetPivotEncoder());
   frc::SmartDashboard::PutNumber  ("Pivot Angle  ", Rot2Deg( GetPivotEncoder() ) );

   frc::SmartDashboard::PutNumber  ("Pivot Angle Pot V", m_pivotAnglePot.GetValue() );
   frc::SmartDashboard::PutNumber  ("Pivot Angle Pot Deg", Pot2Deg() );
   // frc::SmartDashboard::PutNumber  ("Pivot Angle Start Deg", m_startingPivotAngle   );
   // frc::SmartDashboard::PutNumber  ("Pivot Angle Start Enc", m_startingPivotEncoder );

   frc::SmartDashboard::PutBoolean ("Pivot PotVsEnc", CheckPotVsRotAngle() );

   frc::SmartDashboard::PutNumber  ("Upper Motor Temp", m_shooterUpper.GetMotorTemperature() );
   frc::SmartDashboard::PutNumber  ("Lower Motor Temp", m_shooterLower.GetMotorTemperature() );


   
}
