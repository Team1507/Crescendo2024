
#include "commands/CmdAmpTrapDeploy.h"
#include <iostream>
#include "Robot.h"
#include "Constants.h"

CmdAmpTrapDeploy::CmdAmpTrapDeploy() 
{
  AddRequirements(&robotContainer.m_amperatus);
}

void CmdAmpTrapDeploy::Initialize() 
{
  robotContainer.m_amperatus.AmpTrapDeploy();
  std::cout<<"Amp Trap Deploy has started"<<std::endl;
}

void CmdAmpTrapDeploy::Execute() 
{

}

void CmdAmpTrapDeploy::End(bool interrupted) 
{
std::cout<<"Amp Trap Deploy has ended"<<std::endl;
}

bool CmdAmpTrapDeploy::IsFinished() 
{
  return true; 
}

