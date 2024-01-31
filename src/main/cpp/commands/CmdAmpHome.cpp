#include "commands/CmdAmpHome.h"
#include "Robot.h"
#include <iostream>

#define AMP_HOME_POS 0.0

CmdAmpHome::CmdAmpHome() 
{
  AddRequirements(&robotContainer.m_amperatus);
  std::cout<<"amp home start"<<std::endl;
}


void CmdAmpHome::Initialize() 
{
  if(robotContainer.m_amperatus.GetAmpBotLimit())
  {
    robotContainer.m_amperatus.SetAmpAngle(0.0);
    robotContainer.m_amperatus.HoldAmpAngle(AMP_HOME_POS);
    robotContainer.m_amperatus.SetAmpHome(true); //write this function
  }
}


void CmdAmpHome::Execute() 
{

}


void CmdAmpHome::End(bool interrupted) 
{
  std::cout<<"amp home end"<<std::endl;
}


bool CmdAmpHome::IsFinished() 
{
  return false;
}
