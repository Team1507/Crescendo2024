#include "commands/CmdIntakeDeploy.h"
#include <iostream>
#include "Robot.h"
#include "Constants.h"

CmdIntakeDeploy::CmdIntakeDeploy() 
{
  //AddRequirements(&robotContainer.m_intake);
}

void CmdIntakeDeploy::Initialize()
{
  if (!robotContainer.m_shooter.GetFeederPhotoeye())
  {  
    robotContainer.m_intake.IntakeDeploy();
    robotContainer.m_shooter.SetFeederIntakePower(FEEDER_INTAKE_POWER);
    std::cout << "Intake Deployed" << std::endl;
  }
  else
  {
    std::cout << "Note Already In Robot" << std::endl;
  }
}

void CmdIntakeDeploy::Execute() 
{
  
}

void CmdIntakeDeploy::End(bool interrupted) {}

bool CmdIntakeDeploy::IsFinished()
{
  return true;
}
