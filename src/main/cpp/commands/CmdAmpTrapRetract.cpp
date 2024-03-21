
#include "commands/CmdAmpTrapRetract.h"
#include <iostream>
#include "Robot.h"
#include "Constants.h"

CmdAmpTrapRetract::CmdAmpTrapRetract() 
{
  //AddRequirements(&robotContainer.m_amperatus);
}

void CmdAmpTrapRetract::Initialize() 
{
  //robotContainer.m_amperatus.AmpTrapRetract();
  std::cout<<"Amp Trap Retract has started"<<std::endl;
}

void CmdAmpTrapRetract::Execute() 
{

}

void CmdAmpTrapRetract::End(bool interrupted) 
{
  std::cout<<"Amp Trap Retract has ended"<<std::endl;
}

bool CmdAmpTrapRetract::IsFinished() 
{
  return true;
}
