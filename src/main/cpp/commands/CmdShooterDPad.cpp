#include "commands/CmdShooterDPad.h"
#include "Robot.h"


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
      std::cout<< "DPAD UP" << std::endl;
      break;
      
    //----------------------------
    case DPAD_DOWN:
      std::cout<< "DPAD DOWN" << std::endl;
      break;

    //----------------------------
    case DPAD_LEFT:
      std::cout<< "DPAD LEFT" << std::endl;
      break;

    //----------------------------
    case DPAD_RIGHT:
      std::cout<< "DPAD RIGHT" << std::endl;
      break;

    //----------------------------
    default:
      std::cout<< "Unknown DPAD Input" << std::endl;
      break;

  }
}

void CmdShooterDPad::Execute() {}

void CmdShooterDPad::End(bool interrupted) {}

bool CmdShooterDPad::IsFinished() 
{
  return true;
}
