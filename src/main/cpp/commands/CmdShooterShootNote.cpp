#include "commands/CmdShooterShootNote.h"
#include <iostream>
#include "Robot.h"
#include "Constants.h"

CmdShooterShootNote::CmdShooterShootNote(bool status) 
{
  frc::SmartDashboard::PutNumber("FEEDER_SHOOTER_POWER",FEEDER_SHOOTER_POWER);
  m_status = status;
  AddRequirements(&robotContainer.m_shooter);
}

void CmdShooterShootNote::Initialize() 
{
  std::cout << "Shooter Shoot Note Started" << std::endl;
  if(m_status == true)
  {
    robotContainer.m_shooter.SetFeederShooterPower(frc::SmartDashboard::GetNumber("FEEDER_SHOOTER_POWER",0));  
  }
  else
  {
    robotContainer.m_shooter.SetFeederShooterPower(0);
  }
}

void CmdShooterShootNote::Execute() {}

void CmdShooterShootNote::End(bool interrupted) 
{
  std::cout << "Shooter Shoot Note Ended" << std::endl;
}

bool CmdShooterShootNote::IsFinished() 
{
  return true;
}