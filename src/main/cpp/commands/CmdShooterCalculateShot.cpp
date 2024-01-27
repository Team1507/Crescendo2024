#include "commands/CmdShooterCalculateShot.h"
#include <iostream>
#include "Robot.h"

CmdShooterCalculateShot::CmdShooterCalculateShot() 
{
  AddRequirements(&robotContainer.m_shooter);
}

void CmdShooterCalculateShot::Initialize() 
{
  robotContainer.m_shooter.ShooterInterpolate(0.0);
  std::cout << "Shooter Calculate Started" << std::endl;
}

void CmdShooterCalculateShot::Execute() {}

void CmdShooterCalculateShot::End(bool interrupted) 
{
  std::cout << "Shooter Calculate Ended" << std::endl;
}

bool CmdShooterCalculateShot::IsFinished() {
  return false;
}
