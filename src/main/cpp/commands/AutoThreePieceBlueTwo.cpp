#include "commands/AutoThreePieceBlueThree.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"

AutoThreePieceBlueThree::AutoThreePieceBlueThree() {

  AddCommands(

    CmdPrintText("Auto Three Piece Blue Two Started"),
    CmdShooterHome(),
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),
    // Turn Towards Speaker
    CmdShooterShootNote(0),
    CmdIntakeDeploy(),
    // drive backwards
    CmdShooterShootNote(0),
    // arc to note on right
    // rotate towards speaker
    CmdShooterShootNote(0),
    CmdShooterSetPower(0),
    CmdIntakeRetract(),
    CmdPrintText("Auto Three Piece Blue Two Ended")

  );
}
