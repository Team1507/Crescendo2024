
#include "commands/CmdAmpTrapDeploy.h"
#include <iostream>
#include "Robot.h"
#include "Constants.h"

CmdAmpDeploy::CmdAmpDeploy() 
{
  AddRequirements(&robotContainer.m_amperatus);
}

void CmdAmpDeploy::Initialize() 
{
robotContainer.m_amperatus.AmpTrapDeploy();
std::cout<<"Amp Trap Deploy has started"<<std::endl;
}

void CmdAmpDeploy::Execute() 
{

}

void CmdAmpDeploy::End(bool interrupted) 
{
std::cout<<"Amp Trap Deploy has ended"<<std::endl;
}

bool CmdAmpDeploy::IsFinished() 
{
  return true; 
}

