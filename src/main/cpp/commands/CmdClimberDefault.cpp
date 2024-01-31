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
  double leftY = robotContainer.m_topDriver.GetLeftY();
  
  if(robotContainer.m_topDriver.GetBackButtonPressed() && !robotContainer.m_climber.IsClimberBrakeEngaged())
  {
    robotContainer.m_climber.ClimberSetPower(leftY);
  }
}

void CmdClimberDefault::End(bool interrupted) 
{
  std::cout << "Climber End" << std::endl;
}

bool CmdClimberDefault::IsFinished() 
{
  return false;
}