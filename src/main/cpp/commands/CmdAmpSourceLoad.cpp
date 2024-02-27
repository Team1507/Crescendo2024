#include "commands/CmdAmpSourceLoad.h"
#include <iostream>
#include "Robot.h"

CmdAmpSourceLoad::CmdAmpSourceLoad() 
{
  AddRequirements(&robotContainer.m_amperatus);
  AddRequirements(&robotContainer.m_shooter);
}

// Called when the command is initially scheduled.
void CmdAmpSourceLoad::Initialize() 
{
  std::cout << "Amp Source Load Start" << std::endl;
  robotContainer.m_shooter.SetPivotAngle(2); 
  robotContainer.m_amperatus.SetAmpRollerPower(-.1);
}

// Called repeatedly when this Command is scheduled to run
void CmdAmpSourceLoad::Execute() {}

// Called once the command ends or is interrupted.
void CmdAmpSourceLoad::End(bool interrupted) 
{
  std::cout << "Amp Source Load End" << std::endl;
  robotContainer.m_amperatus.SetAmpRollerPower(0);
  robotContainer.m_shooter.SetPivotAngle(0);
}

// Returns true when the command should end.
bool CmdAmpSourceLoad::IsFinished() 
{
  if (  false  )     // <<<--- Needs to be fixed with new PhotoDetector 
  {
    return true;
  }
  else
  {
    return false;
  } 
}
