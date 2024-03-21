// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdShooterAmpRetract.h"

#include "Robot.h"
#include <iostream>
CmdShooterAmpRetract::CmdShooterAmpRetract() 
{
  AddRequirements(&robotContainer.m_shooter);
  std::cout << "Cmd Amp Retract Started" << std::endl;
}

// Called when the command is initially scheduled.
void CmdShooterAmpRetract::Initialize() 
{
  robotContainer.m_shooter.ShooterAmpRetract();
  
}

// Called repeatedly when this Command is scheduled to run
void CmdShooterAmpRetract::Execute() {}

// Called once the command ends or is interrupted.
void CmdShooterAmpRetract::End(bool interrupted) 
{
  std::cout << "Cmd Amp Retract Ended" << std::endl;
}

// Returns true when the command should end.
bool CmdShooterAmpRetract::IsFinished() 
{
  return true;
}
