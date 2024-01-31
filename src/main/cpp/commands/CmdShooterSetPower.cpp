#include "commands/CmdShooterSetPower.h"
#include <iostream>
#include "Robot.h"

CmdShooterSetPower::CmdShooterSetPower(double shooterPower)
{
  m_shooterPower = shooterPower;
}

void CmdShooterSetPower::Initialize() 
{
  robotContainer.m_shooter.SetShooterPower(m_shooterPower);
  std::cout << "Shooter Set Power Started" << std::endl;
}

void CmdShooterSetPower::Execute() 
{
  
}

void CmdShooterSetPower::End(bool interrupted)
{
 std::cout << "Shooter Set Power Ended" << std::endl;
}

bool CmdShooterSetPower::IsFinished() 
{
  return true;
}
