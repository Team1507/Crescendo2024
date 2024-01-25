#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() 
{
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() 
{
  return autos::ExampleAuto(&m_subsystem);
}
