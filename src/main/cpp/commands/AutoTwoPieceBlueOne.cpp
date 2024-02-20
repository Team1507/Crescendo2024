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
#include "commands/CmdDriveStop.h"

AutoTwoPieceBlueOne::AutoTwoPieceBlueOne() {

  AddCommands(

    CmdPrintText("Auto Two Piece Blue One Started"), 
    CmdShooterHome(),// <----
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),

    //Turn to speaker
    CmdDriveTurn2Angle(0.2,-45.0),
    CmdShooterShootNote(),

    //Turn toward note
    CmdDriveTurn2Angle(0.2,45.0),
    CmdShooterSetAngle(PIVOT_HOME_POS),
    CmdIntakeDeploy(),

    //Drive Backwards to pick up note
    CmdDriveToPoint( 0, 60, 0, 2000, true, 10), 
    CmdIntakeRetract(),

    //Rotate to speaker
    CmdDriveTurn2Angle(0.2,-45.0),
    CmdShooterShootNote(),
    CmdShooterSetPower(0),
    CmdDriveStop(),
    CmdPrintText("Auto Two Piece Blue One")
  );
}
