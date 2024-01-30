#include "commands/CmdSetFeederPower.h"
#include <iostream>
#include "Robot.h"

CmdSetFeederPower::CmdSetFeederPower() {}

void CmdSetFeederPower::Initialize() 
{
  robotContainer.m_shooter.SetFeederPower(0.0);
  std::cout << "Feeder Set Power Started" << std::endl;
}

void CmdSetFeederPower::Execute() {}

void CmdSetFeederPower::End(bool interrupted) 
{
  std::cout << "Feeder Set Power Ended" << std::endl;
}

bool CmdSetFeederPower::IsFinished() 
{
  return true;
}
