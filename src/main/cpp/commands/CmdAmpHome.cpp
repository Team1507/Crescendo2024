#include "commands/CmdAmpHome.h"
#include "Robot.h"
#include <iostream>

#define AMP_HOME_POS 0.0

CmdAmpHome::CmdAmpHome() 
{
  AddRequirements(&robotContainer.m_amperatus);
}


void CmdAmpHome::Initialize() 
{
  std::cout<<"Amperatus Home Start"<<std::endl;
  robotContainer.m_amperatus.SetAmpPower(-0.2);  
}


void CmdAmpHome::Execute() 
{

}


void CmdAmpHome::End(bool interrupted) 
{
  robotContainer.m_amperatus.SetAmpAngle(0);
  robotContainer.m_amperatus.HoldAmpAngle(AMP_HOME_POS);
  std::cout<<"Amperatus Home End"<<std::endl;
}


bool CmdAmpHome::IsFinished() 
{
  return robotContainer.m_amperatus.GetAmpBotLimit();
}