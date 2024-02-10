#include <iostream>
#include "Robot.h"
#include "commands/CmdAmpSetRollerPower.h"

CmdAmpSetRollerPower::CmdAmpSetRollerPower(double power) 
{
  m_ampPower = power;
}


void CmdAmpSetRollerPower::Initialize() 
{
  robotContainer.m_amperatus.SetAmpRollerPower(m_ampPower);
  std::cout << "Amperatus Set Roller Power Started" << std::endl;
}


void CmdAmpSetRollerPower::Execute() {}


void CmdAmpSetRollerPower::End(bool interrupted) 
{
  std::cout << "Amperatus Set Roller Power Ended" << std::endl;
}


bool CmdAmpSetRollerPower::IsFinished() {
  return true;
}
