// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveForceSteerAngle.h"
#include "Robot.h"

CmdDriveForceSteerAngle::CmdDriveForceSteerAngle( float angle ) 
{
  m_angle = angle;
  AddRequirements({ &robotContainer.m_drivetrain });
}

void CmdDriveForceSteerAngle::Initialize() 
{
  m_timer.Reset();
  m_timer.Start();

  robotContainer.m_drivetrain.ForceSteerAngle(m_angle);
}

void CmdDriveForceSteerAngle::Execute() {}

void CmdDriveForceSteerAngle::End(bool interrupted) 
{
  robotContainer.m_drivetrain.Stop();
}

bool CmdDriveForceSteerAngle::IsFinished() 
{

  if ( m_timer.HasElapsed( units::second_t( 2.0 )  ) )
  {
    m_timer.Stop();
    return true;
  }

  return false;
}
