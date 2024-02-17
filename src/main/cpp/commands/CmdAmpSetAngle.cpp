#include "commands/CmdAmpSetAngle.h"
#include <iostream>
#include "Robot.h"

CmdAmpSetAngle::CmdAmpSetAngle() 
{

}

void CmdAmpSetAngle::Initialize() 
{
  robotContainer.m_amperatus.SetAmpAngle(0.0);
  std::cout << "Amperatus Angle Set" << std::endl;  
}

void CmdAmpSetAngle::Execute() 
{

}

void CmdAmpSetAngle::End(bool interrupted) 
{

}

bool CmdAmpSetAngle::IsFinished() 
{
  return true;
}
