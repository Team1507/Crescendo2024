#include "Robot.h"
#include <iostream>
#include "commands/CmdClimberClimb.h"


CmdClimberClimb::CmdClimberClimb()
{
  AddRequirements(&robotContainer.m_climber);
}


void CmdClimberClimb::Initialize() 
{
  std::cout << "Cmd Climer Climb Started" << std::endl;
  robotContainer.m_climber.ClimberBrakeDisengage();

}


void CmdClimberClimb::Execute()
{
  double leftY = robotContainer.m_topDriver.GetLeftY();
  robotContainer.m_climber.ClimberSetPower(leftY);
}


void CmdClimberClimb::End(bool interrupted) 
{
  robotContainer.m_climber.ClimberBrakeEngage();
  robotContainer.m_climber.ClimberSetPower(0.0);
  std::cout << "Cmd Climer Climb Ended" << std::endl;
}


bool CmdClimberClimb::IsFinished()
{
  return false;
}
