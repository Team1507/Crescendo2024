#include "subsystems/Amperatus.h"
#include <frc/smartdashboard/SmartDashboard.h>

Amperatus::Amperatus() 
{
    m_ampMotor.RestoreFactoryDefaults();
    m_ampMotorPID.SetP(0.0);
    m_ampMotorPID.SetI(0.0);
    m_ampMotorPID.SetD(0.0);

    m_ampMotorPID.SetSmartMotionAllowedClosedLoopError(0.0);
    m_ampMotorPID.SetOutputRange(-0.3, 0.3, 0);

    m_ampTOF.SetRangingMode(frc::TimeOfFlight::RangingMode::kShort, 50.0);  //Max 24ms sample rate per datasheet
    m_ampTOF.SetRangeOfInterest(8,8,12,12);   //Use center 4 pixels for FOV
}

void Amperatus::Periodic() 
{
    frc::SmartDashboard::PutBoolean("AMP TOF", GetAmpTOF());
}

void   Amperatus::SetAmpPower(double power)
{
    m_ampMotor.Set(power);
}

void   Amperatus::SetAmpAngle(double position)
{
    m_ampMotorPID.SetReference(position, rev::CANSparkMax::ControlType::kPosition);
}

void   Amperatus::ResetAmpEncoder()
{
    m_ampEncoder.SetPosition(0);
}

void   Amperatus::SetAmpRollerPower(double power)
{
    m_ampRoller.Set(power);
}

double Amperatus::GetAmpPower(void)
{
    return m_ampMotor.Get();
}

double Amperatus::GetAmpAngle(void)
{
    return m_ampEncoder.GetPosition();
}

double Amperatus::GetAmpRollerPower(void)
{
    return m_ampRoller.Get();
}

bool   Amperatus::GetAmpTopLimit(void)
{
    return true;
}

bool   Amperatus::GetAmpBotLimit(void)
{
    return true;
}

bool   Amperatus::GetAmpTOF(void)
{
    if( m_ampTOF.GetRange() < 75.0 )return true; 
    else return false;   
}