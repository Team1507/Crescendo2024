#include "Robot.h"
#include "commands/CmdShooterSetTargetID.h"

CmdShooterSetTargetID::CmdShooterSetTargetID(int id) 
{
  m_id = id;
}
void CmdShooterSetTargetID::Initialize() 
{
  robotContainer.m_photonvision.SetTargetId(m_id);
}
