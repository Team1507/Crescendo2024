#include <iostream>
#include "Robot.h"
#include "commands/CmdAmpEject.h"

CmdAmpEject::CmdAmpEject(double power) 
{
  m_ampPower = power;
}


void CmdAmpEject::Initialize() 
{
  robotContainer.m_amperatus.SetAmpRollerPower(m_ampPower);
  std::cout << "Amperatus Eject Started" << std::endl;
}


void CmdAmpEject::Execute() {}


void CmdAmpEject::End(bool interrupted) 
{
  std::cout << "Amperatus Eject Ended" << std::endl;
}


bool CmdAmpEject::IsFinished() {
  return true;
}
