#include "commands/CmdShooterDefault.h"
#include "Robot.h"
#include <iostream>
#include "Constants.h"

CmdShooterDefault::CmdShooterDefault() 
{
  AddRequirements(&robotContainer.m_shooter);
}


void CmdShooterDefault::Initialize() 
{
  m_shooting = false;
  m_interpolation = false;
  std:: cout << "Shooter default started" << std::endl;
}


void CmdShooterDefault::Execute() 
{

  if( (robotContainer.m_topDriver.GetRightTriggerAxis() > 0.9) && !m_shooting)
  {
    robotContainer.m_shooter.SetFeederShooterPower(FEEDER_SHOOTER_POWER);
    m_shooting = true;
  } 
  else if((robotContainer.m_topDriver.GetRightTriggerAxis() < 0.9) && m_shooting)
  {
    robotContainer.m_shooter.SetFeederShooterPower(0);
    m_shooting = false;
  }
  
  if((robotContainer.m_topDriver.GetLeftTriggerAxis() > 0.9) && !m_interpolation)
  {
    robotContainer.m_shooter.ShooterInterpolate(0.0);
    m_interpolation = true;
  }
  else if((robotContainer.m_topDriver.GetLeftTriggerAxis() < 0.9) && m_interpolation)
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


