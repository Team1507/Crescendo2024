#include "commands/CmdIntakeDeploy.h"
#include <iostream>
#include "Robot.h"

CmdIntakeDeploy::CmdIntakeDeploy() 
{
  AddRequirements(&robotContainer.m_intake);
}

void CmdIntakeDeploy::Initialize()
{
  robotContainer.m_intake.IntakeDeploy();
  std::cout << "Intake Deploy Started" << std::endl;
}

void CmdIntakeDeploy::Execute() 
{
  
}

void CmdIntakeDeploy::End(bool interrupted) 
{
    std::cout << "Intake Deploy Ended" << std::endl;
}

bool CmdIntakeDeploy::IsFinished()
{
  if(robotContainer.m_intake.IntakeIsPieceDetected() == true)
  {
    robotContainer.m_intake.IntakeRetract();

    return true;
  }
}
