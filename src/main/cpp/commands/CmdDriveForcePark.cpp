#include "Robot.h"
#include "commands/CmdDriveForcePark.h"

CmdDriveForcePark::CmdDriveForcePark() 
{
  AddRequirements(&robotContainer.m_drivetrain);
}

void CmdDriveForcePark::Initialize() 
{
  m_timer.Reset();
  m_timer.Start();

}


void CmdDriveForcePark::Execute() 
{
  robotContainer.m_drivetrain.ForcePark();
}


void CmdDriveForcePark::End(bool interrupted) 
{
    robotContainer.m_drivetrain.Stop();
}


bool CmdDriveForcePark::IsFinished()
 {
    if ( m_timer.HasElapsed( units::second_t( 0.5)  ) )
  {
    m_timer.Stop();
    return true;
  }
  return false;
}
