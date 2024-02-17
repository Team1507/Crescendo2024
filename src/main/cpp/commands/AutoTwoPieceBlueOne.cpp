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
  CmdShooterHome(),
  CmdShooterSetAngle(0),
  CmdShooterSetPower(0),
  CmdShooterShootNote(),
  //Rotate to staring position
  CmdIntakeDeploy(),
  //Drive backwards
   CmdDriveToPoint( 0, 60, 0, 2000, true, 10),
  //Rotate to speaker
  CmdDriveTurn2Angle( 0.2, -45.0 ),
  CmdShooterSetPower(0),
  CmdIntakeRetract(),
  CmdPrintText("Auto Two Piece Blue One")
  );
}
