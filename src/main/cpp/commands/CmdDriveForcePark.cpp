#include "Robot.h"
#include "commands/CmdDriveForcePark.h"

CmdDriveForcePark::CmdDriveForcePark() {

}

void CmdDriveForcePark::Initialize() 
{
  robotContainer.m_drivetrain.ForcePark();
}


void CmdDriveForcePark::Execute() {}


void CmdDriveForcePark::End(bool interrupted) {}


bool CmdDriveForcePark::IsFinished() {
  return true;
}
