#include "commands/CmdShooterShootNote.h"
#include <iostream>
#include "Robot.h"
#include "Constants.h"

CmdShooterShootNote::CmdShooterShootNote() 
{
  frc::SmartDashboard::PutNumber("FEEDER_SHOOTER_POWER",FEEDER_SHOOTER_POWER);
  AddRequirements(&robotContainer.m_shooter);
}

void CmdShooterShootNote::Initialize() 
{
  std::cout << "Shooter Shoot Note Started" << std::endl;
  // if(m_status == true)
  // {
    robotContainer.m_shooter.SetFeederShooterPower(frc::SmartDashboard::GetNumber("FEEDER_SHOOTER_POWER",0));  
    m_timer.Reset();
    m_timer.Start();
  // }
  // else
  // {
  //   robotContainer.m_shooter.SetFeederShooterPower(0);
  // }
}

void CmdShooterShootNote::Execute() {}

void CmdShooterShootNote::End(bool interrupted) 
{
  std::cout << "Shooter Shoot Note Ended" << std::endl;
  robotContainer.m_shooter.SetFeederShooterPower(0);
  m_timer.Stop();
}

bool CmdShooterShootNote::IsFinished() 
{

  const units::second_t timeout = units::second_t(1.0); 

  if(m_timer.Get() >= timeout)
  {
    return true;
  }
  else 
  {
    return false;
  }
}