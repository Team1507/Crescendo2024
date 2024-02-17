
#include "commands/AutoFourPieceRedTwo.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"

AutoFourPieceRedTwo::AutoFourPieceRedTwo() {
{
  AddCommands(

    CmdPrintText("Auto Four Piece Red Two Started"), 
    CmdShooterHome(),
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),
    CmdShooterShootNote(),
    CmdIntakeDeploy(),
    //DriveBackwards
    CmdShooterShootNote(),
    //Arc to note on left
    CmdIntakeDeploy(),
    //Rotate to speaker
    CmdShooterShootNote(),
    //Rotate back to starting position
    CmdIntakeRetract(),
    //Drive back
    CmdIntakeDeploy(),
    CmdIntakeRetract(),
    //Drive forwards
    //Rotate to speaker
    CmdShooterSetAngle(0),
    CmdShooterShootNote(),
    CmdShooterSetPower(0),
    CmdPrintText("Auto Four Piece Red Two Ended")

  );
}
}