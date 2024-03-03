#include <iostream>
#include "Robot.h"
#include "commands/CmdAmpIntake.h"

CmdAmpIntake::CmdAmpIntake(double power) 
{
  m_ampPower = power;
}


void CmdAmpIntake::Initialize() 
{
  robotContainer.m_amperatus.SetAmpRollerPower(-1.0);
  std::cout << "Amperatus Intake Started" << std::endl;
}


void CmdAmpIntake::Execute() {}


void CmdAmpIntake::End(bool interrupted) 
{
  std::cout << "Amperatus Intake Ended" << std::endl;
  robotContainer.m_amperatus.SetAmpRollerPower(0.0);
}


bool CmdAmpIntake::IsFinished() 
{
  return robotContainer.m_amperatus.GetAmpPhotoeye();
}