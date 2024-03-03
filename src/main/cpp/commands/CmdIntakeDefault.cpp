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
  m_noteCount = 0;
}


void CmdIntakeDefault::Execute() 
{
  if(robotContainer.m_intake.IntakeIsDeployed() && robotContainer.m_shooter.GetFeederPhotoeye())
  {

    m_noteCount++;

    
    if(m_noteCount >= 2 )
    {
      std::cout<<"Note Seen"<<std::endl;
      // if(!frc::DriverStation::IsAutonomous())
      // {
      robotContainer.m_intake.IntakeRetract();
      // }
      robotContainer.m_shooter.SetFeederIntakePower(0);
    }



  }
  else
  {
    m_noteCount = 0;
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
