#include "commands/AutoThreePieceRedOne.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"

AutoThreePieceRedOne::AutoThreePieceRedOne() {

  AddCommands(

    CmdPrintText("Auto Three Piece Red One Started"),
    CmdShooterHome(),
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),
    // Turn Towards Speaker
    CmdShooterShootNote(0),
    CmdIntakeDeploy(),
    // drive backwards
    CmdShooterShootNote(0),
    // arc to note on left
    // rotate towards speaker
    CmdShooterShootNote(0),
    CmdShooterSetPower(0),
    CmdIntakeRetract(),
    CmdPrintText("Auto Three Piece Red One Ended")

  );
}
