
#include "commands/AutoFourPieceBlueTwo.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"

AutoFourPieceBlueTwo::AutoFourPieceBlueTwo() {
{
  AddCommands(

    CmdPrintText("Auto Four Piece Blue Two Started"), 
    CmdShooterHome(),
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),
    CmdShooterShootNote(0),
    CmdIntakeDeploy(),
    //DriveBackwards
    CmdShooterShootNote(0),
    //Arc to note on right
    CmdIntakeDeploy(),
    //Rotate to speaker
    CmdShooterShootNote(0),
    //Rotate back to starting position
    CmdIntakeRetract(),
    //Drive back
    CmdIntakeDeploy(),
    CmdIntakeRetract(),
    //Drive forwards
    //Rotate to speaker
    CmdShooterSetAngle(0),
    CmdShooterShootNote(0),
    CmdShooterSetPower(0),
    CmdPrintText("Auto Four Piece Blue Two Ended")

  );
}
}