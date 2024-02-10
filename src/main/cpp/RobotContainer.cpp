#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterCalculateShot.h"
#include "commands/CmdAmpEject.h"
#include "commands/CmdAmpIntake.h"
#include "commands/CmdAmpSetAngle.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdClimberClimb.h"

RobotContainer::RobotContainer() 
{
  //m_chooser.SetDefaultOption("Auto Do Nothing", &m_autoDoNothing);


  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
  m_topDriver_LeftBumper.OnTrue(new CmdIntakeDeploy());
  m_topDriver_LeftBumper.OnFalse(new CmdIntakeRetract()); 
  
  m_topDriver_XButton.WhileTrue(new CmdAmpIntake(0.3)); //amp intake

  m_topDriver_BButton.OnTrue(new CmdAmpEject(-0.5)); //amp eject
  m_topDriver_BButton.OnFalse(new CmdAmpEject(0.0)); //amp eject stop

  m_topDriver_RightBumper.OnTrue(new CmdAmpSetAngle()); //amp up
  m_topDriver_RightBumper.OnFalse(new CmdAmpSetAngle()); //amp down

  m_topDriver_BackButton.WhileTrue(new CmdClimberClimb()); //climber climb

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() 
 {
   return (frc2::CommandPtr) AutoDoNothing();
 }
