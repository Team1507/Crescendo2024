#include "commands/AutoThreePieceBlueOne.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"


AutoThreePieceBlueOne::AutoThreePieceBlueOne() {

  AddCommands(

  CmdPrintText("Auto Three Piece Blue One Started"), 
  CmdShooterHome(),
  CmdShooterSetAngle(0),
  CmdShooterSetPower(0),
  // rotate to speaker
  CmdShooterShootNote(0),
  // Rotate to starting pos
  CmdIntakeDeploy(),
  // drive backwards
  // drive forwards
  // rotate to speaker
  CmdShooterShootNote(0),
  // Rotate to starting position
  // drive backwards
  // drive forwards
  // rotate to speaker
  CmdShooterShootNote(0),
  CmdShooterSetPower(0),
  CmdIntakeRetract(),
  CmdPrintText("Auto Three Piece Blue One Finished")

  );
}
