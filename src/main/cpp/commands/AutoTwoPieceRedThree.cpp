#include "commands/AutoTwoPieceRedThree.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"

AutoTwoPieceRedThree::AutoTwoPieceRedThree() {
  AddCommands(

  CmdPrintText("Auto Two Piece Red Three Started"), 
  CmdShooterHome(),

  CmdShooterSetAngle(0),
  CmdShooterSetPower(0),
  CmdShooterShootNote(0),
  //Rotate to staring position
  CmdIntakeDeploy(),
  //Drive backwards
  //Rotate to speaker
  CmdShooterSetPower(0),
  CmdIntakeRetract(),
  CmdPrintText("Auto Two Piece Red Three Ended")
  );
}
