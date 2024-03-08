#include "Robot.h"
#include "commands/CmdAmpPowerUp.h"

CmdAmpPowerUp::CmdAmpPowerUp() {}

void CmdAmpPowerUp::Initialize() 
{
  robotContainer.m_amperatus.SetAmpPower(0.3);
}

void CmdAmpPowerUp::Execute() {}

void CmdAmpPowerUp::End(bool interrupted) 
{
  robotContainer.m_amperatus.SetAmpPower(-0.3);
  for(int i = 1; i<= 2;)
  {
    if (robotContainer.m_amperatus.GetAmpAngle() > -0.1 && robotContainer.m_amperatus.GetAmpAngle() < 0.1)
    {
      i++;
    }
  }
  robotContainer.m_amperatus.SetAmpPower(0);
}

bool CmdAmpPowerUp::IsFinished() 
{
  return true;
}
