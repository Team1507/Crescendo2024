#include "commands/AutoTwoPieceBlueOne.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/"
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"

AutoTwoPieceBlueOne::AutoTwoPieceBlueOne() {
  AddCommands(

  CmdPrintText("Auto Two Piece Blue One"), 
  CmdShooterHome(),
  CmdShooterSetAngle(0),
  CmdShooterSetPower(0),
  //April Tag Thingy
  //DriveTrain Thingy
  CmdIntakeDeploy(),
  //Drive Train Thingy
  CmdIntakeRetract(),
  CmdPrintText("Auto Two Piece Blue One")
  );
}
