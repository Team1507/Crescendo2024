#include "commands/AutoRedShakeNBake.h"
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
#include "commands/CmdDriveTurn2Angle.h"
#include <frc2/command/WaitCommand.h>

AutoRedShakeNBake::AutoRedShakeNBake() 
{
  AddCommands(
  CmdDriveClearAll(),
  CmdPrintText("Shake N Bake Baby Red"),
  frc2::WaitCommand(0.1_s),

  //Move and Shoot First Note
  CmdShooterSetPower(0.8),
  CmdShooterSetAngle(37),
  CmdDriveToPoint(0, 24, 10, 8000, false, 10),
  CmdShooterShootNote(),
  CmdDriveToPoint(0, 74, 10, 13000, false, 10),

  //Move to second note
  CmdShooterSetAngle(50),
  CmdDriveToPoint(48,200,0,13000,false,10),
  CmdIntakeDeploy(),
  CmdDriveToPoint(48,249,0,6000,true,10),

  //Go to shoot second note
  CmdDriveToPoint(0, 50, 0, 13000, false, 10 ),
  CmdDriveToPoint(0, 0, 25, 6000, true, 10),
  CmdShooterShootNote(),

  //Move and shoot third note
  CmdIntakeDeploy(),
  CmdDriveToPoint(28, 37, 20, 8000, false, 10),
  CmdDriveToPoint(-19, 0, 0, 8000, true, 10),
  CmdShooterShootNote(),
  CmdIntakeRetract(),

  //Move and shoot forth note
  CmdShooterSetAngle(43),
  CmdIntakeDeploy(),
  CmdDriveToPoint(-28, 37, 0, 6000, false, 10),
  CmdDriveToPoint(-56, 20, -30, 8000, true, 10),
  CmdShooterShootNote(),
  CmdIntakeRetract(),
  CmdShooterSetAngle(41),

  //Move and shoot Fith note
  CmdIntakeDeploy(),
  CmdDriveToPoint(-78, 35, -40, 3000, false, 10),
  CmdDriveToPoint(-65, 25, -20, 3000, true, 10),
  CmdShooterShootNote(),
  CmdIntakeRetract(),

  CmdDriveStop(),
  CmdPrintText("Shaked N Baked Red")
  );
}
