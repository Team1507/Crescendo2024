
#include "commands/CmdShooterAmpDeploy.h"

#include "Robot.h"
#include <iostream>

CmdShooterAmpDeploy::CmdShooterAmpDeploy() 
{
  AddRequirements(&robotContainer.m_shooter);
  std::cout << "Cmd Amp Deploy Started" << std::endl;
}

// Called when the command is initially scheduled.
void CmdShooterAmpDeploy::Initialize() 
{
  robotContainer.m_shooter.ShooterAmpDeploy();
}

// Called repeatedly when this Command is scheduled to run
void CmdShooterAmpDeploy::Execute() {}

// Called once the command ends or is interrupted.
void CmdShooterAmpDeploy::End(bool interrupted) 
{
  std::cout << "Cmd Amp Deploy Ended" << std::endl;
}

// Returns true when the command should end.
bool CmdShooterAmpDeploy::IsFinished() {
  return true;
}
