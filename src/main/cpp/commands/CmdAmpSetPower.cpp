#include "commands/CmdAmpSetPower.h"
#include <iostream>
#include "Robot.h"

CmdAmpSetPower::CmdAmpSetPower(double power) 
{
  m_power = power;
}

void CmdAmpSetPower::Initialize() 
{
  robotContainer.m_amperatus.SetAmpPower(m_power);
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
