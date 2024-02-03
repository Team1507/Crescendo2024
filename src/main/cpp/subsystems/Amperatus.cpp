#include "subsystems/Amperatus.h"
#include <frc/smartdashboard/SmartDashboard.h>

Amperatus::Amperatus() = default;

void Amperatus::Periodic() {}

void   Amperatus::SetAmpPower(double power)
{
    m_ampMotor.Set(power);
}

void   Amperatus::SetAmpAngle(double angle)
{
    m_ampEncoder.SetPosition(angle);
}

void   Amperatus::SetAmpHome(bool home)
{

}

void   Amperatus::HoldAmpAngle(double position)
{

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

void Amperatus::AmpTrapDeploy(void)
{
    if (!m_ampIsDeployed && !Amperatus::GetAmpPhotoEye())
    {
    m_ampDoubleSolenoid.Set(frc::DoubleSolenoid::kForward);
    m_ampMotor.Set(frc::SmartDashboard::GetNumber("AMPERATUS_POWER",0.0));
    m_ampIsDeployed = true;
    }
} 

void Amperatus::AmpTrapRetract(void)
{
    if (m_ampIsDeployed)
    {
    m_ampDoubleSolenoid.Set(frc::DoubleSolenoid::kReverse);
    m_ampMotor.Set(0.0);
    m_ampIsDeployed = false;
    }
}

bool Amperatus::AmpTrapIsDeployed(void)
{
    return m_ampIsDeployed;
}

bool   Amperatus::GetAmpTopLimit(void)
{
    return m_ampTopLimit.Get();
}

bool   Amperatus::GetAmpBotLimit(void)
{
    return m_ampBotLimit.Get();
}

bool   Amperatus::GetAmpPhotoEye(void)
{
    return m_ampPhotoEye.Get();
}