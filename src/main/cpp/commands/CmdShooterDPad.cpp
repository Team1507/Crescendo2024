#include "commands/CmdShooterDPad.h"
#include "subsystems/Shooter.h"

CmdShooterDPad::CmdShooterDPad(dPadPosition position) 
{
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void CmdShooterDPad::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdShooterDPad::Execute() {}

// Called once the command ends or is interrupted.
void CmdShooterDPad::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdShooterDPad::IsFinished() {
  return false;
}
