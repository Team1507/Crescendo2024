#include "commands/CmdShooterSetPower.h"
#include <iostream>
#include "Robot.h"

CmdShooterSetPower::CmdShooterSetPower() 
{
  AddRequirements(&robotContainer.m_shooter);
}

void CmdShooterSetPower::Initialize() 
{
  robotContainer.m_shooter.SetShooterPower(0.6);
  std::cout << "Shooter Set Power Started" << std::endl;
}

void CmdShooterSetPower::Execute() {}

void CmdShooterSetPower::End(bool interrupted) 
{
  std::cout << "Shooter Set Power Ended" << std::endl;
}

bool CmdShooterSetPower::IsFinished() 
{
  return false;
}
