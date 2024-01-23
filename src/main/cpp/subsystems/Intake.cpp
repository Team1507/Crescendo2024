// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

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
    if(!m_isIntaking)
    {
        m_doubleSolenoid.Set(frc::DoubleSolenoid::kForward);
        m_isIntaking = true;
    }
}

void Intake::IntakeRetract(void)
{
    if(m_isIntaking)
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

// This method will be called once per scheduler run
void Intake::Periodic() {}
