#include "commands/CmdShooterSetAngle.h"
#include <iostream>
#include "Robot.h"

CmdShooterSetAngle::CmdShooterSetAngle() {}

void CmdShooterSetAngle::Initialize() 
{
  robotContainer.m_shooter.SetPivotAngle(0.0);
  std::cout << "Shooter Set Angle Started" << std::endl;
}

void CmdShooterSetAngle::Execute() {}

void CmdShooterSetAngle::End(bool interrupted) 
{
  std::cout << "Shooter Set Angle Ended" << std::endl;
}

bool CmdShooterSetAngle::IsFinished() 
{
  return true;
}
