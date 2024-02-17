#include "commands/AutoTwoPieceBlueOne.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"


AutoTwoPieceBlueOne::AutoTwoPieceBlueOne() {
  AddCommands(

  CmdPrintText("Auto Two Piece Blue One Started"), 
  CmdShooterHome(),// <----
  CmdShooterSetAngle(0),
  CmdShooterSetPower(0),

  CmdDriveTurn2Angle(0.2,-45.0),//Turn to speaker

  CmdShooterShootNote(),

  CmdDriveTurn2Angle(0.2,45.0),//Turn toward note

  CmdShooterSetAngle(PIVOT_HOME_POS),
  CmdIntakeDeploy(),

  CmdDriveToPoint( 0, 60, 0, 2000, true, 10), //Drive Backwards to pick up note

  CmdIntakeRetract(),

  CmdDriveTurn2Angle(0.2,-45.0),//Rotate to speaker

  CmdShooterShootNote(),
  CmdPrintText("Auto Two Piece Blue One")
  );
}
