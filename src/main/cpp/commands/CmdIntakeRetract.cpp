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
  std::cout << "Intake Retract Started" << std::endl;
}

void CmdIntakeRetract::Execute() 
{

}

void CmdIntakeRetract::End(bool interrupted) 
{
  std::cout << "Intake Retract Ended" << std::endl;
}

bool CmdIntakeRetract::IsFinished() 
{
  return true;
}
