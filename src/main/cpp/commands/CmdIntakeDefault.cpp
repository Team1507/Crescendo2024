#include "commands/CmdIntakeDefault.h"
#include "Robot.h"
#include <iostream>

CmdIntakeDefault::CmdIntakeDefault() 
{
  AddRequirements(&robotContainer.m_intake);
}


void CmdIntakeDefault::Initialize() 
{
  std::cout << "Intake Default Start" << std::endl;
}


void CmdIntakeDefault::Execute() 
{
  if(robotContainer.m_intake.IntakeIsDeployed() && robotContainer.m_shooter.GetFeederTOFDetect())
  {
    if(!frc::DriverStation::IsAutonomous())
    {
      robotContainer.m_intake.IntakeRetract();
    }

    robotContainer.m_shooter.SetFeederIntakePower(0);
  } 
}


void CmdIntakeDefault::End(bool interrupted) 
{
  std::cout << "Intake Default Ended" << std::endl;
}


bool CmdIntakeDefault::IsFinished() 
{
  return false;
}
