#include "subsystems/Intake.h"
#include <frc/smartdashboard/SmartDashboard.h>

Intake::Intake() 
{
    m_isIntaking = true;
}

void Intake::IntakeInit()
{
  frc::SmartDashboard::PutNumber("INTAKE_POWER",0.6);
}

void Intake::IntakeDeploy(void)
{
    if(!m_isIntaking && !m_gamePieceDetect.Get())
    {
        m_doubleSolenoid.Set(frc::DoubleSolenoid::kForward);
        m_intakeMotor.Set(0.5);
        m_isIntaking = true;
    }
}

void Intake::IntakeRetract(void)
{
    if(m_isIntaking && m_gamePieceDetect.Get())
    {
        m_doubleSolenoid.Set(frc::DoubleSolenoid::kReverse);
        m_isIntaking = false;
    }
}

void Intake::IntakeSetPower(double power)
{
    m_intakeMotor.Set(power);
}

double Intake::IntakeGetPower(void)
{
    return m_intakeMotor.Get();
}

bool Intake::IntakeIsDeployed(void)
{
    return m_isIntaking;
}

bool Intake::IntakeIsPieceDetected(void)
{
    return m_gamePieceDetect.Get();
}

void Intake::Periodic() {}
