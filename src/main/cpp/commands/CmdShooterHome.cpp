#include "commands/CmdShooterHome.h"
#include <iostream>
#include "Robot.h"

#define PIVOT_HOME_POS 0.0

CmdShooterHome::CmdShooterHome() 
{
  AddRequirements(&robotContainer.m_shooter);
}

void CmdShooterHome::Initialize() 
{
  robotContainer.m_shooter.SetPivotAngle(PIVOT_HOME_POS);
  std::cout << "Shooter Home Started" << std::endl;
}

void CmdShooterHome::Execute() {}

void CmdShooterHome::End(bool interrupted) 
{
  std::cout << "Shooter Home Started" << std::endl;
}

bool CmdShooterHome::IsFinished() {
  return false;
}
