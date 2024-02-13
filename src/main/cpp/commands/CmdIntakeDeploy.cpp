#include "commands/CmdIntakeDeploy.h"
#include <iostream>
#include "Robot.h"
#include "Constants.h"

CmdIntakeDeploy::CmdIntakeDeploy() 
{
  AddRequirements(&robotContainer.m_intake);
}

void CmdIntakeDeploy::Initialize()
{
  robotContainer.m_intake.IntakeDeploy();
  robotContainer.m_shooter.SetFeederIntakePower(FEEDER_INTAKE_POWER);
  std::cout << "Intake Deploy Started" << std::endl;
}

void CmdIntakeDeploy::Execute() 
{
  
}

void CmdIntakeDeploy::End(bool interrupted) 
{
  std::cout << "Intake Deploy Ended" << std::endl;
  robotContainer.m_intake.IntakeRetract();
  robotContainer.m_shooter.SetFeederIntakePower(0);
}

bool CmdIntakeDeploy::IsFinished()
{
  if(robotContainer.m_shooter.GetFeederTOF())
  {
    return true;
  }
  else
  {
    return false; 
  }
}
