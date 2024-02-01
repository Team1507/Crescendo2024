#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterCalculateShot.h"
#include "commands/CmdAmpSetRollerPower.h"
#include "commands/CmdAmpSetAngle.h"
#include "commands/CmdSetFeederPower.h"

RobotContainer::RobotContainer() 
{
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
  m_topDriver_LeftBumper.OnTrue(new CmdIntakeDeploy());
  m_topDriver_LeftBumper.OnFalse(new CmdIntakeRetract()); 

  
  m_topDriver_XButton.OnTrue(new CmdAmpSetRollerPower()); //amp intake
  m_topDriver_BButton.OnTrue(new CmdAmpSetRollerPower()); //amp eject

  m_topDriver_RightBumper.OnTrue(new CmdAmpSetAngle()); //amp up
  m_topDriver_RightBumper.OnFalse(new CmdAmpSetAngle()); //amp down

  

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() 
{
  return autos::ExampleAuto(&m_subsystem);
}
