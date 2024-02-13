#include "commands/CmdShooterSourceLoad.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include <iostream>
#include "Robot.h"

CmdShooterSourceLoad::CmdShooterSourceLoad() 
{
  AddRequirements(&robotContainer.m_shooter);
}

// Called when the command is initially scheduled.
void CmdShooterSourceLoad::Initialize() 
{
  std::cout << "Shooter Source Load Start" << std::endl;
  robotContainer.m_shooter.SetShooterPower(-.1); 
  robotContainer.m_shooter.SetPivotAngle(3); 
  robotContainer.m_shooter.SetFeederIntakePower(-.1); 
}

// Called repeatedly when this Command is scheduled to run
void CmdShooterSourceLoad::Execute() {}

// Called once the command ends or is interrupted.
void CmdShooterSourceLoad::End(bool interrupted) 
{
  std::cout << "Shooter Source Load End" << std::endl;
  robotContainer.m_shooter.SetShooterPower(0);
  robotContainer.m_shooter.SetFeederIntakePower(0);
  robotContainer.m_shooter.SetPivotAngle(0);
}

// Returns true when the command should end.
bool CmdShooterSourceLoad::IsFinished() 
{
  if (robotContainer.m_shooter.GetFeederTOF()) 
  {
    return true;
  }
  else
  {
    return false;
  } 
}
