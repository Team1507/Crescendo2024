#include "commands/AutoTwoPieceMiddle.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <---- Drive train
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveStop.h"

AutoTwoPieceMiddle::AutoTwoPieceMiddle() //add drivetrain
 {
  AddCommands(
    
    
    CmdPrintText("Auto Two Piece Middle Started"), 
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),
    CmdShooterShootNote(),
    CmdShooterSetAngle(PIVOT_HOME_POS),
    CmdIntakeDeploy(),

    //drive to note
    CmdDriveToPoint(0, 60, 0, 2000, true, 10),
    CmdShooterSetAngle(0),
    CmdShooterShootNote(),
    CmdShooterSetPower(0),
    CmdIntakeRetract(),
    CmdDriveStop(),
    CmdPrintText("Auto Two Piece Middle Completed")
  );
}
