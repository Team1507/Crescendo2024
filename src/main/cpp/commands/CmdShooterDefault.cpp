#include "commands/CmdShooterDefault.h"
#include "Robot.h"
#include <iostream>

CmdShooterDefault::CmdShooterDefault() 
{
  m_shooting = false;
  m_interpolation = false;
  AddRequirements(&robotContainer.m_shooter);
}


void CmdShooterDefault::Initialize() 
{
  std:: cout << "Shooter default started" << std::endl;
}


void CmdShooterDefault::Execute() 
{

  if( (robotContainer.m_topDriver.GetRightTriggerAxis() > 0.9) && !m_shooting)
  {
    robotContainer.m_shooter.SetFeederPower(0.0);// # will be changed
    m_shooting = true;
  } 
  else if(m_shooting)
  {
    robotContainer.m_shooter.SetFeederPower(0.0);
    m_shooting = false;
  }
  
  if(robotContainer.m_topDriver.GetLeftTriggerAxis() )
  {
    robotContainer.m_shooter.ShooterInterpolate(0.0);
    m_interpolation = true;
  }
  else if(m_interpolation)
  {
    m_interpolation = false;
  }

}


void CmdShooterDefault::End(bool interrupted) 
{
  std:: cout << "Shooter default ended" << std::endl;
}


bool CmdShooterDefault::IsFinished() 
{
  return false;
}


