#include "commands/CmdShooterDPad.h"
#include "Robot.h"

//*********NON-MODE SHIFT CONSTANTS*********

#define IDLE_POWER    0.1
#define IDLE_ANGLE    52

#define SPEAKER_POWER 0.8
#define SPEAKER_ANGLE 52

#define PODIUM_POWER  0.8
#define PODIUM_ANGLE  36

#define GENERAL_POWER 0.8
#define GENERAL_ANGLE 40

//**************MODE SHIFT CONSTANTS*************

#define AMP_ANGLE     25

#define TRAP_ANGLE    25

#define SOURCE_ANGLE  46

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

      if(robotContainer.m_topDriver.GetAButton())
      {
        std::cout<< "DPAD UP A" << std::endl;
        robotContainer.m_shooter.SetShooterPower(IDLE_POWER);
        robotContainer.m_shooter.SetPivotAngle(AMP_ANGLE);
      }    
      else
      {
        std::cout<< "DPAD UP" << std::endl;
        robotContainer.m_shooter.SetShooterPower(SPEAKER_POWER);
        robotContainer.m_shooter.SetPivotAngle(SPEAKER_ANGLE);
      }

      break;
      
    //----------------------------
    case DPAD_DOWN:

      if(robotContainer.m_topDriver.GetAButton())
      {
        std::cout<< "DPAD DOWN A" << std::endl;
        robotContainer.m_shooter.SetShooterPower(IDLE_POWER);
        robotContainer.m_shooter.SetPivotAngle(TRAP_ANGLE);
      }
      else
      {
        std::cout<< "DPAD DOWN" << std::endl;
        robotContainer.m_shooter.SetShooterPower(IDLE_POWER);
        robotContainer.m_shooter.SetPivotAngle(IDLE_ANGLE);
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
        robotContainer.m_shooter.SetShooterPower(PODIUM_POWER);
        robotContainer.m_shooter.SetPivotAngle(PODIUM_ANGLE);
      }
      break;

    //----------------------------
    case DPAD_RIGHT:
      if(robotContainer.m_topDriver.GetAButton())
      {
        std::cout<< "DPAD right A" << std::endl;
        robotContainer.m_shooter.SetPivotAngle(SOURCE_ANGLE);
      }
      else
      {
        std::cout<< "DPAD RIght" << std::endl;
        robotContainer.m_shooter.SetShooterPower(GENERAL_POWER);
        robotContainer.m_shooter.SetPivotAngle(GENERAL_ANGLE);
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
