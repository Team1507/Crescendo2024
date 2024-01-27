#include "commands/CmdShooterSetAngle.h"
#include <iostream>
#include "Robot.h"

CmdShooterSetAngle::CmdShooterSetAngle() 
{
  AddRequirements(&robotContainer.m_shooter);
}

void CmdShooterSetAngle::Initialize() 
{
  robotContainer.m_shooter.SetPivotAngle(0.0);
  std::cout << "Shooter Set Angle Started" << std::endl;
}

void CmdShooterSetAngle::Execute() {}

void CmdShooterSetAngle::End(bool interrupted) 
{
  std::cout << "Shooter Set Velocity Ended" << std::endl;
}

bool CmdShooterSetAngle::IsFinished() {
  return false;
}
