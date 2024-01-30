#include "subsystems/Intake.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Robot.h"

#define INTAKE_POWER 0

Intake::Intake() 
{
  m_doubleSolenoid.Set(frc::DoubleSolenoid::kReverse);
  m_intakeMotor.Set(0.0);
  m_isIntaking = false;

  frc::SmartDashboard::PutNumber("INTAKE_POWER",INTAKE_POWER);

}

void Intake::IntakeDeploy(void)
{
    if(!m_isIntaking && !robotContainer.m_shooter.GetFeederPhotoEye())
    {
        m_doubleSolenoid.Set(frc::DoubleSolenoid::kForward);
        m_intakeMotor.Set( frc::SmartDashboard::GetNumber("INTAKE_POWER",0.0) );
        m_isIntaking = true;
    }
}

void Intake::IntakeRetract(void)
{
    if( m_isIntaking )
    {
        m_doubleSolenoid.Set(frc::DoubleSolenoid::kReverse);
        m_intakeMotor.Set(0.0);
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

void Intake::Periodic() {}
