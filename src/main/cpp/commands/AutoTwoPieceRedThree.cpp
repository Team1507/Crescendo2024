#include "commands/AutoTwoPieceRedThree.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdDriveToPoint.h"

AutoTwoPieceRedThree::AutoTwoPieceRedThree() {
  AddCommands(

  CmdPrintText("Auto Two Piece Red Three Started"), 
  CmdShooterHome(),

  CmdShooterSetAngle(0),
  CmdShooterSetPower(0),
  CmdShooterShootNote(),
  //Rotate to staring position
  CmdIntakeDeploy(),
  //Drive backwards
  CmdDriveToPoint( 0, 60, 0, 2000, true, 10),
  CmdIntakeRetract(),

  //Rotate to speaker
  CmdDriveTurn2Angle( 0.2, -45.0 ),
  CmdShooterSetPower(0),
  CmdPrintText("Auto Two Piece Red Three Ended")
  );
}
