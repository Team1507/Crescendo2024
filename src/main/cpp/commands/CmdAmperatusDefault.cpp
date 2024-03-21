#include "commands/CmdAmperatusDefault.h"
#include <iostream>
#include "Robot.h"

#define MANUAL_DEADBAND 0.8

#define AMP_SLOW_POWER 0.3

CmdAmperatusDefault::CmdAmperatusDefault() 
{
  //AddRequirements(&robotContainer.m_amperatus);
}

void CmdAmperatusDefault::Initialize() 
{
  std::cout<<"Amp default start"<<std::endl;
}

void CmdAmperatusDefault::Execute() 
{
  if (robotContainer.m_topDriver.GetRightX() > MANUAL_DEADBAND)
  {
    //robotContainer.m_amperatus.SetAmpPower(AMP_SLOW_POWER);
    //robotContainer.m_amperatus.SetAmpAngle(robotContainer.m_amperatus.GetAmpAngle());
  }
  else if (robotContainer.m_topDriver.GetRightX() < -MANUAL_DEADBAND)
  {
    //robotContainer.m_amperatus.SetAmpPower(-AMP_SLOW_POWER);
    //robotContainer.m_amperatus.SetAmpAngle(robotContainer.m_amperatus.GetAmpAngle())
  }
  else
  {
    //robotContainer.m_amperatus.SetAmpPower(0); //CHANGE LATER, ADD HAND OFFS!!!!!
  }
}

void CmdAmperatusDefault::End(bool interrupted) 
{
  std::cout<<"Amp default end"<<std::endl;
}

bool CmdAmperatusDefault::IsFinished() 
{
  return false;
}
