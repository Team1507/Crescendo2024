#include "commands/CmdAmperatusDefault.h"
#include <iostream>
#include "Robot.h"

CmdAmperatusDefault::CmdAmperatusDefault() 
{
  AddRequirements(&robotContainer.m_amperatus);
  std::cout<<"Amp default start"<<std::endl;
}

void CmdAmperatusDefault::Initialize() 
{

}

void CmdAmperatusDefault::Execute() 
{

}

void CmdAmperatusDefault::End(bool interrupted) 
{
  std::cout<<"Amp default end"<<std::endl;
}

bool CmdAmperatusDefault::IsFinished() 
{
  return false;
}
