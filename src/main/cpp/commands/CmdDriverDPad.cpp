

#include "commands/CmdDriverDPad.h"
#include "Robot.h"
#include "subsystems/DriverFeedback.h"


CmdDriverDPad::CmdDriverDPad(dPadPosition position) 
{
  m_position = position;
}


void CmdDriverDPad::Initialize() 
{

  switch( m_position )
  {

    //----------------------------
    case DPAD_UP:

      std::cout<< "Driver DPAD UP" << std::endl;
      robotContainer.m_driverfeedback.BlinkLED( COLOR_BLUE );
  
      break;
      
    //----------------------------
    case DPAD_DOWN:

      std::cout<< "Driver DPAD DOWN" << std::endl;
      robotContainer.m_driverfeedback.BlinkLED( COLOR_YELLOW );

      break;

    //----------------------------
    case DPAD_LEFT:

      std::cout<< "Driver DPAD LEFT" << std::endl;
      robotContainer.m_driverfeedback.BlinkLED( COLOR_PURPLE );

      break;

    //----------------------------
    case DPAD_RIGHT:

      std::cout<< "Driverf DPAD RIght" << std::endl;
      robotContainer.m_driverfeedback.BlinkLED( COLOR_TEAL );

      break;

    //----------------------------
    default:
      std::cout<< "Unknown Driver DPAD Input" << std::endl;
      break;

  }

}
