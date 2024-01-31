#include "subsystems/Amperatus.h"

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