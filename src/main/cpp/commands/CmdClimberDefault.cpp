#include "commands/CmdClimberDefault.h"
#include "subsystems/Climber.h"
#include "Robot.h"
#include <iostream>


CmdClimberDefault::CmdClimberDefault() 
{
  AddRequirements(&robotContainer.m_climber); 
}

void CmdClimberDefault::Initialize() 
{
  std::cout << "Climber Init" << std::endl;
}

void CmdClimberDefault::Execute() 
{
  
}

void CmdClimberDefault::End(bool interrupted) 
{
  std::cout << "Climber End" << std::endl;
}

bool CmdClimberDefault::IsFinished() 
{
  return false;
}