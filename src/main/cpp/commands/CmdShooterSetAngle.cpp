#include "commands/CmdShooterSetAngle.h"
#include <iostream>
#include "Robot.h"

CmdShooterSetAngle::CmdShooterSetAngle(double shooterAngle) 
{
  m_shooterAngle = shooterAngle;
}

void CmdShooterSetAngle::Initialize() 
{
  robotContainer.m_shooter.SetPivotAngle(m_shooterAngle);
  std::cout << "Shooter Set Angle" << std::endl;
}

void CmdShooterSetAngle::Execute() {}

void CmdShooterSetAngle::End(bool interrupted) 
{

}

bool CmdShooterSetAngle::IsFinished() 
{
  return true;
}
