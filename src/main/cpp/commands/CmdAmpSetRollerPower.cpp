#include <iostream>
#include "robot.h"
#include "commands/CmdAmpSetRollerPower.h"

CmdAmpSetRollerPower::CmdAmpSetRollerPower() 
{

}


void CmdAmpSetRollerPower::Initialize() 
{
  robotContainer.m_amperatus.SetAmpRollerPower(0.0);
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
