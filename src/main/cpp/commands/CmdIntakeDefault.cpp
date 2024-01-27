#include "commands/CmdIntakeDefault.h"
#include "Robot.h"
#include <iostream>

CmdIntakeDefault::CmdIntakeDefault() 
{
  AddRequirements(&robotContainer.m_intake); 
}

void CmdIntakeDefault::Initialize() 
{
  std::cout << "Intake Default Initaialize" << std::endl;
}

void CmdIntakeDefault::Execute() {}

void CmdIntakeDefault::End(bool interrupted) 
{
  std::cout << "Intake Default Ended" << std::endl;
}

bool CmdIntakeDefault::IsFinished() 
{
  return false;
}
