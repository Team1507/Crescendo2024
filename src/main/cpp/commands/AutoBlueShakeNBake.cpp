#include "commands/AutoBlueShakeNBake.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <---- Drive train
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdWaitShooterSpeed.h"
#include "commands/CmdDriveClearAll.h"
#include <frc2/command/WaitCommand.h>
AutoBlueShakeNBake::AutoBlueShakeNBake() 
{
  AddCommands(
  CmdDriveClearAll(),
  CmdPrintText("Shake N Bake Baby"),

  //Move and Shoot First Note
  CmdShooterSetPower(0.8),
  CmdShooterSetAngle(28),
  CmdDriveToPoint(0,74,-15,10000,false,10),
  CmdShooterShootNote(),

  //Move to second note
  CmdDriveToPoint(-43,200,0,10000,false,10),
  CmdIntakeDeploy(),
  CmdDriveToPoint(-43,249,0,5000,true,10),

  CmdDriveStop(),
  CmdPrintText("Shaked N Baked")
  );
}
