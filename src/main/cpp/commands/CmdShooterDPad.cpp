#include "commands/CmdShooterDPad.h"
#include "commands/CmdShooterSourceLoad.h"
#include "Robot.h"

CmdShooterDPad::CmdShooterDPad(dPadPosition position) 
{
  m_position = position;
}

void CmdShooterDPad::Initialize() 
{
  double testPower = frc::SmartDashboard::GetNumber("SHOOTER_POWER",0.0);

  switch( m_position )
  {

    //----------------------------
    case DPAD_UP:

      if (robotContainer.m_topDriver.GetLeftBumperPressed())
      {
        robotContainer.m_climber.ClimberSetPower(0.9);
      }
      else
      {
        robotContainer.m_climber.ClimberSetPower(0);
      }
      break;
      
    //----------------------------
    case DPAD_DOWN:
      if (robotContainer.m_topDriver.GetLeftBumperPressed())
      {
        robotContainer.m_climber.ClimberSetPower(-0.9);
      }
      else
      {
        robotContainer.m_climber.ClimberSetPower(0);
      }
      break;

    //----------------------------
    case DPAD_LEFT:
      
      break;

    //----------------------------
    case DPAD_RIGHT:
      
      break;

    //----------------------------
    default:
       if(robotContainer.m_topDriver.GetAButton())
      {
        std::cout<< "Unknown DPAD Input A" << std::endl;
      }
      else
      {
        std::cout<< "Unknown DPAD Input" << std::endl;
      }
      break;

  }
}

void CmdShooterDPad::Execute() {}

void CmdShooterDPad::End(bool interrupted) {}

bool CmdShooterDPad::IsFinished() 
{
  return true;
}
