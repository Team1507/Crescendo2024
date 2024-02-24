#include "commands/AutoTwoPieceRedOne.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drive train
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdDriveStop.h"

AutoTwoPieceRedOne::AutoTwoPieceRedOne() {

  AddCommands(

    CmdPrintText("Auto Two Piece Red One Started"), 
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),

    //turn to speaker
    CmdDriveTurn2Angle(0.2,45.0),
    CmdShooterShootNote(),

    //Turn to note
    CmdDriveTurn2Angle(0.2,-45.0),
    CmdShooterSetAngle(0),
    CmdShooterSetAngle(PIVOT_HOME_POS),
    CmdIntakeDeploy(),

    //Go to note
    CmdDriveToPoint( 0, 60, 0, 2000, true, 10),
    CmdShooterShootNote(),
    CmdShooterSetPower(0),
    CmdIntakeRetract(),
    CmdDriveStop(),
    CmdPrintText("Auto Two Piece Red One Completed")


  );
}
