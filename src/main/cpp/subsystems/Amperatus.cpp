#include "subsystems/Amperatus.h"
#include <frc/smartdashboard/SmartDashboard.h>

Amperatus::Amperatus() 
{
    m_ampMotor.RestoreFactoryDefaults();
    // m_ampMotorPID.SetP(0.0);
    // m_ampMotorPID.SetI(0.0);
    // m_ampMotorPID.SetD(0.0);

    // m_ampMotorPID.SetSmartMotionAllowedClosedLoopError(0.0);
    // m_ampMotorPID.SetOutputRange(-0.3, 0.3, 0);

    m_ampDoubleSolenoid.Set(frc::DoubleSolenoid::kReverse);   //Make sure not set to deploy

}

void Amperatus::Periodic() 
{

}

void   Amperatus::SetAmpPower(double power)
{
    m_ampMotor.Set(power);
}

// void   Amperatus::SetAmpAngle(double position)
// {
//     m_ampMotorPID.SetReference(position, rev::CANSparkMax::ControlType::kPosition);
// }

// void   Amperatus::ResetAmpEncoder()
// {
//     m_ampEncoder.SetPosition(0);
// }

void   Amperatus::SetAmpRollerPower(double power)
{
    // m_ampRoller.Set(power);
}

double Amperatus::GetAmpPower(void)
{
    return m_ampMotor.Get();
}

void   Amperatus::AmpTrapDeploy(void)
{
    m_ampDoubleSolenoid.Set(frc::DoubleSolenoid::kForward);
}

void   Amperatus::AmpTrapRetract(void)
{
    //SHOULD NEVER RETRACT EVER!!
    //This should be done manually
}

// double Amperatus::GetAmpAngle(void)
// {
//     return m_ampEncoder.GetPosition();
// }

double Amperatus::GetAmpRollerPower(void)
{
    return 0;
    // return m_ampRoller.Get();
}



