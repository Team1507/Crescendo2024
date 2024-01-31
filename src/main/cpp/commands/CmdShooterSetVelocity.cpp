#include "commands/CmdShooterSetVelocity.h"
#include <iostream>
#include "Robot.h"

CmdShooterSetVelocity::CmdShooterSetVelocity() 
{
  AddRequirements(&robotContainer.m_shooter);
}

void CmdShooterSetVelocity::Initialize() 
{
  robotContainer.m_shooter.SetShooterRPM(0.3);
  std::cout << "Shooter Set Velocity Started" << std::endl;
}

void CmdShooterSetVelocity::Execute() {}

void CmdShooterSetVelocity::End(bool interrupted) 
{
  std::cout << "Shooter Set Velocity Ended" << std::endl;
}

bool CmdShooterSetVelocity::IsFinished() {
  return false;
}
