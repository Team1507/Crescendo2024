#include "commands/CmdShooterDPad.h"
#include "commands/CmdShooterSourceLoad.h"
#include "Robot.h"

//*********NON-MODE SHIFT CONSTANTS*********

#define IDLE_POWER    0.1

#define SPEAKER_POWER 0.8
#define SPEAKER_ANGLE 52

#define PODIUM_POWER  0.8
#define PODIUM_ANGLE  34.5

#define GENERAL_POWER 0.8
#define GENERAL_ANGLE 40

//**************MODE SHIFT CONSTANTS*************

#define AMP_ANGLE     35
#define AMP_POWER     0.5

#define SOURCE_ANGLE  42.5

#define CLIMB_ANGLE   15

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
        robotContainer.m_shooter.SetShooterPower(AMP_POWER);
        robotContainer.m_shooter.SetPivotAngle(AMP_ANGLE);
        robotContainer.m_shooter.ShooterAmpDeploy();
        // robotContainer.m_driverfeedback.BlinkLED(COLOR_YELLOW);
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
        robotContainer.m_shooter.SetPivotAngle(SOURCE_ANGLE);
        robotContainer.m_driverfeedback.BlinkLED(COLOR_TEAL);
      }
      else
      {
        std::cout<< "DPAD DOWN" << std::endl;
        robotContainer.m_shooter.SetShooterPower(IDLE_POWER);
        robotContainer.m_driverfeedback.BlinkLED(COLOR_PURPLE);\
        if(robotContainer.m_shooter.IsShooterAmpDeployed())
        {
          robotContainer.m_shooter.ShooterAmpRetract();
        }
      }

      break;

    //----------------------------
    case DPAD_LEFT:
      if(robotContainer.m_topDriver.GetAButton())
      {
        std::cout<< "DPAD LEFT A" << std::endl;
        robotContainer.m_shooter.SetShooterPowerDB();
      }
      else
      {
        std::cout<< "DPAD LEFT" << std::endl;
        robotContainer.m_shooter.SetShooterPower(0.8);
        // robotContainer.m_shooter.SetShooterPower(GENERAL_POWER);
        // robotContainer.m_shooter.SetPivotAngle(GENERAL_ANGLE);
      }
      break;

    //----------------------------
    case DPAD_RIGHT:
      if(robotContainer.m_topDriver.GetAButton())
      {
        std::cout<< "DPAD RIGHT A" << std::endl;
        robotContainer.m_shooter.SetShooterPower(0);
        robotContainer.m_shooter.SetPivotAngle(CLIMB_ANGLE);
      }
      else
      {
        std::cout<< "DPAD RIGHT" << std::endl;
        robotContainer.m_shooter.SetShooterPower(PODIUM_POWER);
        robotContainer.m_shooter.SetPivotAngle(PODIUM_ANGLE);
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
