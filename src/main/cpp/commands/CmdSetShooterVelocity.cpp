#include "commands/CmdSetShooterVelocity.h"
#include <iostream>
#include "Robot.h"

CmdSetShooterVelocity::CmdSetShooterVelocity() 
{
  AddRequirements(&robotContainer.m_shooter);
}

void CmdSetShooterVelocity::Initialize() 
{
  robotContainer.m_shooter.SetShooterRPM(0.3);
  std::cout << "Shooter Set Velocity Started" << std::endl;
}

void CmdSetShooterVelocity::Execute() {}

void CmdSetShooterVelocity::End(bool interrupted) 
{
  std::cout << "Shooter Set Velocity Ended" << std::endl;
}

bool CmdSetShooterVelocity::IsFinished() {
  return false;
}
