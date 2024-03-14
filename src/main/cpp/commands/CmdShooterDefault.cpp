#include "commands/CmdShooterDefault.h"
#include "Robot.h"
#include <iostream>
#include "Constants.h"

#define SHOOTER_DEADBAND_CONSTANT 0.9
#define INTERPOLATION_DEADBAND_CONSTANT 0.9

#define PIVOT_DEADBAND_CONSTANT 0.5

#define PIVOT_SLOW_POWER 0.4

CmdShooterDefault::CmdShooterDefault() 
{
  AddRequirements(&robotContainer.m_shooter);
}


void CmdShooterDefault::Initialize() 
{
  m_shooting          = false;
  m_interpolation     = false;
  m_manualPivotEnable = false;

  std:: cout << "Shooter default started" << std::endl;
}


void CmdShooterDefault::Execute() 
{

//******************SHOOTER CONTROLS*********************
//*******************************************************

  if( (robotContainer.m_topDriver.GetRightTriggerAxis() > SHOOTER_DEADBAND_CONSTANT) && !m_shooting)
  {
    robotContainer.m_shooter.SetFeederShooterPower(FEEDER_SHOOTER_POWER);
    m_shooting = true;
  } 
  else if((robotContainer.m_topDriver.GetRightTriggerAxis() < SHOOTER_DEADBAND_CONSTANT) && m_shooting)
  {
    robotContainer.m_shooter.SetFeederShooterPower(0);
    m_shooting = false;
  }
  
  // //Need to think about this one....
  // if((robotContainer.m_topDriver.GetLeftTriggerAxis() > INTERPOLATION_DEADBAND_CONSTANT) && !m_interpolation)
  // {
  //   robotContainer.m_shooter.ShooterInterpolate(0.0);
  //   m_interpolation = true;
  // }
  // else if((robotContainer.m_topDriver.GetLeftTriggerAxis() < INTERPOLATION_DEADBAND_CONSTANT) && m_interpolation)
  // {
  //   m_interpolation = false;
  // }

//*********************PIVOT MANUAL*********************
//******************************************************

  if (robotContainer.m_topDriver.GetRightY() > PIVOT_DEADBAND_CONSTANT  &&   !robotContainer.m_shooter.GetPivotBotLimit() )
  {
    robotContainer.m_shooter.SetPivotPower(-PIVOT_SLOW_POWER);
    //robotContainer.m_shooter.SetPivotAngle(robotContainer.m_shooter.GetPivotAngle());
    m_manualPivotEnable = true;
  }
  else if (robotContainer.m_topDriver.GetRightY() < -PIVOT_DEADBAND_CONSTANT    )
  {
    robotContainer.m_shooter.SetPivotPower(PIVOT_SLOW_POWER);
    //robotContainer.m_shooter.SetPivotAngle(robotContainer.m_shooter.GetPivotAngle());
    m_manualPivotEnable = true;

  }
  else if( m_manualPivotEnable )
  {
    robotContainer.m_shooter.SetPivotPower(0);
    robotContainer.m_shooter.SetPivotAngle(robotContainer.m_shooter.GetPivotAngle());
    m_manualPivotEnable = false;
  }


  //PIVOT SAFETY SWITCH
  if( robotContainer.m_shooter.GetPivotBotLimit() )
  {
    robotContainer.m_shooter.SetPivotPower(0);
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


