#include "commands/CmdIntakeRetract.h"
#include <iostream>
#include "Robot.h"

CmdIntakeRetract::CmdIntakeRetract() 
{
  AddRequirements(&robotContainer.m_intake);
}

void CmdIntakeRetract::Initialize() 
{
  robotContainer.m_intake.IntakeRetract();
  robotContainer.m_shooter.SetFeederIntakePower(0);
  std::cout << "Intake Retracted" << std::endl;
}

void CmdIntakeRetract::Execute() 
{

}

void CmdIntakeRetract::End(bool interrupted) 
{

}

bool CmdIntakeRetract::IsFinished() 
{
  return true;
}
