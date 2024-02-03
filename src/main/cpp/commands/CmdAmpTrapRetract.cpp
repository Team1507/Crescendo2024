
#include "commands/CmdAmpTrapRetract.h"
#include <iostream>
#include "Robot.h"
#include "Constants.h"

CmdAmpRetract::CmdAmpRetract() 
{
  AddRequirements(&robotContainer.m_amperatus);
}

void CmdAmpRetract::Initialize() 
{
  robotContainer.m_amperatus.AmpTrapRetract();
  std::cout<<"Amp Trap Retract has started"<<std::endl;
}

void CmdAmpRetract::Execute() 
{

}

void CmdAmpRetract::End(bool interrupted) 
{
  std::cout<<"Amp Trap Retract has ended"<<std::endl;
}

bool CmdAmpRetract::IsFinished() 
{
  return true;
}
