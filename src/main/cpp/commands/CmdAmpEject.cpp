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
  std::cout << "Amperatus Ejected" << std::endl;
}


void CmdAmpEject::Execute() {}


void CmdAmpEject::End(bool interrupted) 
{

}


bool CmdAmpEject::IsFinished() {
  return true;
}
