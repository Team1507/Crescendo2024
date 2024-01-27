#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"

RobotContainer::RobotContainer() 
{
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
  m_topDriver_LeftBumper.OnTrue(new CmdIntakeDeploy());
  m_topDriver_LeftBumper.OnFalse(new CmdIntakeRetract()); 
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() 
{
  return autos::ExampleAuto(&m_subsystem);
}
