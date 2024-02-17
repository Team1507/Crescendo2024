#include "commands/CmdShooterHome.h"
#include <iostream>
#include "Robot.h"
#include "Constants.h"

CmdShooterHome::CmdShooterHome() 
{
  AddRequirements(&robotContainer.m_shooter);
}

void CmdShooterHome::Initialize() 
{
  std::cout << "Shooter Home Started." << std::endl;
  robotContainer.m_shooter.SetPivotPower(-0.2);
}

void CmdShooterHome::Execute() 
{

}

void CmdShooterHome::End(bool interrupted) 
{
  robotContainer.m_shooter.ResetPivotEncoder();
  robotContainer.m_shooter.SetPivotAngle(PIVOT_HOME_POS);
  std::cout << "Shooter Home Ended." << std::endl;
}

bool CmdShooterHome::IsFinished() 
{
  return robotContainer.m_shooter.GetLowerPivotLimitSW();
}
