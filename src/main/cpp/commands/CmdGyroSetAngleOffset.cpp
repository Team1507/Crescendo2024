// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdGyroSetAngleOffset.h"
#include "Robot.h"


CmdGyroSetAngleOffset::CmdGyroSetAngleOffset( float angle) 
{
  m_angle      = angle;
}


void CmdGyroSetAngleOffset::Initialize() 
{
  robotContainer.m_drivetrain.SetGyroAngleOffset(m_angle);
}
