#include "commands/CmdAmpSetPower.h"
#include <iostream>
#include "Robot.h"

CmdAmpSetPower::CmdAmpSetPower() 
{

}

void CmdAmpSetPower::Initialize() 
{
  //robotContainer.m_amperatus.SetAmpPower(0.0);
  std::cout << "Amperatus Power Set" << std::endl;
}

void CmdAmpSetPower::Execute() 
{

}

void CmdAmpSetPower::End(bool interrupted) 
{

}

bool CmdAmpSetPower::IsFinished() 
{
  return true;
}
