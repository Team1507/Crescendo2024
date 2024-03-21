#include <iostream>
#include "Robot.h"
#include "commands/CmdAmpEject.h"

CmdAmpEject::CmdAmpEject(double power) 
{
  m_ampPower = power;
}


void CmdAmpEject::Initialize() 
{
  //robotContainer.m_amperatus.SetAmpRollerPower(1.0);
  std::cout << "Amperatus Ejected" << std::endl;
}


void CmdAmpEject::Execute() {}


void CmdAmpEject::End(bool interrupted) 
{
 //robotContainer.m_amperatus.SetAmpRollerPower(0.0);
}


bool CmdAmpEject::IsFinished() 

{
  return false;
}
