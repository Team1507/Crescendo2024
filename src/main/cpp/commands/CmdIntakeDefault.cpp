#include "commands/CmdIntakeDefault.h"
#include "Robot.h"

CmdIntakeDefault::CmdIntakeDefault() 
{
  AddRequirements(&robotContainer.m_intake);
}


void CmdIntakeDefault::Initialize() 
{
  
}


void CmdIntakeDefault::Execute() 
{
  
}


void CmdIntakeDefault::End(bool interrupted) 
{

}


bool CmdIntakeDefault::IsFinished() 
{
  return false;
}
