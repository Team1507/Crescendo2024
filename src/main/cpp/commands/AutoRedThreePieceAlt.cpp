#include "commands/AutoRedThreePieceAlt.h"
#include "commands/CmdPrintText.h"
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
#include "commands/CmdDriveTurn2Angle.h"

AutoRedThreePieceAlt::AutoRedThreePieceAlt() 
{
  AddCommands(
  CmdPrintText("Auto Red Three Piece Alt Started"),
  CmdDriveClearAll(),
  CmdShooterSetPower(.8),
  CmdShooterSetAngle(33),
  CmdWaitShooterSpeed(),

  //move and shoot first note
  CmdDriveToPoint(18, 46, -42, 5000, true, 10),
  CmdShooterShootNote(),

  //get second note
  CmdShooterSetAngle(34.5),
  CmdDriveToPoint(-60, 117, 0, 11000, false, 10),
  CmdDriveToPoint(-60, 200, 0, 13000, false, 10),
  CmdIntakeDeploy(),
  CmdDriveToPoint(-60, 249, 0, 6000, false, 10),

  //go to shoot second note
  CmdDriveToPoint(-60, 200, 0, 13000, false, 10),
  CmdIntakeRetract(),
  CmdDriveToPoint(18, 46, -54, 10000, true, 10),
  CmdShooterShootNote(),

  //get third note
  CmdDriveToPoint(-60, 200, 41, 13000, false, 10),
  CmdIntakeDeploy(),
  CmdDriveToPoint(0, 259, 41, 7000, false, 10),

  //go to shoot third note
  CmdDriveToPoint(-48, 200, 0, 13000, false, 10),
  CmdIntakeRetract(),
  CmdDriveToPoint(18, 46, -54, 10000, true, 10),
  CmdShooterShootNote(),

  CmdShooterSetPower(0),
  CmdPrintText("Auto Red Three Piece Alt Ended"),
  CmdDriveStop()
  );
}
