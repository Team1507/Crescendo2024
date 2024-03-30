#include "commands/CmdShooterFeederEject.h"
#include <iostream>
#include "Robot.h"
#include "Constants.h"

#define FEEDER_EJECT_POWER -0.8

CmdShooterFeederEject::CmdShooterFeederEject() 
{
  
}

void CmdShooterFeederEject::Initialize() 
{
  std::cout << "Eject Note Started" << std::endl;
}

void CmdShooterFeederEject::Execute() 
{
  robotContainer.m_shooter.SetFeederIntakePower(FEEDER_EJECT_POWER);
}

void CmdShooterFeederEject::End(bool interrupted) 
{
  robotContainer.m_shooter.SetFeederIntakePower(0);
  std::cout << "Eject Note Ended" << std::endl;
}

bool CmdShooterFeederEject::IsFinished() 
{
  return false;
}
