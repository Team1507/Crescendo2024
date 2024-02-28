#include "commands/CmdShooterDPad.h"
#include "Robot.h"

#define SPEAKER_POWER 0.4
#define IDLE_POWER 0.1

CmdShooterDPad::CmdShooterDPad(dPadPosition position) 
{
  m_position = position;
}

void CmdShooterDPad::Initialize() 
{
  switch( m_position )
  {

    //----------------------------
    case DPAD_UP:

      if(robotContainer.m_topDriver.GetAButton())
      {
        std::cout<< "DPAD UP A" << std::endl;
      }    
      else
      {
        std::cout<< "DPAD UP" << std::endl;
        robotContainer.m_shooter.SetShooterPower(SPEAKER_POWER);
      }

      break;
      
    //----------------------------
    case DPAD_DOWN:

      if(robotContainer.m_topDriver.GetAButton())
      {
        std::cout<< "DPAD DOWN A" << std::endl;
      }
      else
      {
        std::cout<< "DPAD DOWN" << std::endl;
        robotContainer.m_shooter.SetShooterPower(IDLE_POWER);
      }

      break;

    //----------------------------
    case DPAD_LEFT:
      if(robotContainer.m_topDriver.GetAButton())
      {
        std::cout<< "DPAD LEFT A" << std::endl;
      }
      else
      {
        std::cout<< "DPAD LEFT" << std::endl;
      }
      break;

    //----------------------------
    case DPAD_RIGHT:
      if(robotContainer.m_topDriver.GetAButton())
      {
        std::cout<< "DPAD right A" << std::endl;
      }
      else
      {
        std::cout<< "DPAD RIght" << std::endl;
      }
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
