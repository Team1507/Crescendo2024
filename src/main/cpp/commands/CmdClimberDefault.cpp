#include "commands/CmdClimberDefault.h"
#include "subsystems/Climber.h"
#include "Robot.h"


CmdClimberDefault::CmdClimberDefault() 
{
  AddRequirements(&robotContainer.m_climber); 
}

void CmdClimberDefault::Initialize() {}

void CmdClimberDefault::Execute() 
{
  
  
  double leftY = robotContainer.m_topDriver.GetLeftY();
  

  if(robotContainer.m_topDriver.GetBackButtonPressed() && !robotContainer.m_climber.IsClimberBrakeEngaged())
  {
      robotContainer.m_climber.ClimberSetPower(leftY);
  }
}

void CmdClimberDefault::End(bool interrupted) {}

bool CmdClimberDefault::IsFinished() 
{
  return false;
}