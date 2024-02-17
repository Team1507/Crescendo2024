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

    CmdDriveTurn2Angle(0.2,45.0),//turn to speaker

    CmdShooterShootNote(),

    CmdDriveTurn2Angle(0.2,-45.0),//Turn to note

    CmdShooterSetAngle(PIVOT_HOME_POS),
    CmdIntakeDeploy(),

    CmdDriveToPoint( 0, 60, 0, 2000, true, 10),//Go to note

    CmdShooterShootNote(),
    CmdShooterSetPower(0),

    CmdIntakeRetract(),
    CmdPrintText("Auto Two Piece Blue Three Completed")


  );
}
