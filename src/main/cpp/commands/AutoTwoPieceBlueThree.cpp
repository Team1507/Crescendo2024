#include "commands/AutoTwoPieceBlueThree.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drive train
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"

AutoTwoPieceBlueThree::AutoTwoPieceBlueThree() {

  AddCommands(

    CmdPrintText("Auto Two Piece Blue Three Started"), 
    CmdShooterHome(),// <----
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),

    //DriveTrain rotate 
    CmdDriveTurn2Angle( 0.2, -45.0 ),
    CmdShooterShootNote(),
    CmdShooterHome(), // <---
    CmdIntakeDeploy(),

    //DriveTrain backward
    CmdDriveToPoint( 0, 60, 0, 2000, true, 10),
    CmdIntakeRetract(),
    CmdShooterSetPower(0),
    CmdPrintText("Auto Two Piece Blue Three Completed")


  );
}
