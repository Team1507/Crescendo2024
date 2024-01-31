#include "commands/CmdAmpSetAngle.h"
#include <iostream>
#include "Robot.h"

CmdAmpSetAngle::CmdAmpSetAngle() 
{

}

void CmdAmpSetAngle::Initialize() 
{
  robotContainer.m_amperatus.SetAmpAngle(0.0);
  std::cout << "Amperatus Set Angle Started" << std::endl;  
}

void CmdAmpSetAngle::Execute() 
{

}

void CmdAmpSetAngle::End(bool interrupted) 
{
  std::cout << "Amperatus Set Angle Ended" << std::endl;  
}

bool CmdAmpSetAngle::IsFinished() 
{
  return true;
}
