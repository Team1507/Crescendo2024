#include "commands/AutoBlueThreePieceRight.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <---- Drive train
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdWaitShooterSpeed.h"
#include "commands/CmdDriveClearAll.h"
#include <frc2/command/WaitCommand.h>
#include "commands/CmdDriveTurn2Angle.h"
AutoBlueThreePieceRight::AutoBlueThreePieceRight() 
{
 AddCommands(
    CmdPrintText("Auto Blue Three Piece Right Started"),
    CmdDriveClearAll(),

    //Turn Too And Shoot Starting Note
    CmdShooterSetAngle(45),
    CmdShooterSetPower(0.8),
    CmdWaitShooterSpeed(),
    CmdDriveTurn2Angle(0.3, 40),
    CmdShooterShootNote(),

    //Go to second note
    CmdShooterSetAngle(37),
    CmdIntakeDeploy(),
    CmdDriveToPoint(0, 33, 0, 4000, false, 10),
    CmdDriveToPoint(15, 28, 40, 2000, true, 10),
    CmdIntakeRetract(),
    CmdShooterShootNote(),

    //Moving to third piece
    CmdDriveToPoint(115, 145, -20, 10000, false, 10),
    CmdDriveToPoint(96, 205, -20, 8000, false, 10),
    CmdIntakeDeploy(),
    CmdDriveToPoint(75, 257, -20, 6000, false, 10),

    // Drive Back Home
    CmdDriveToPoint(105, 145, 0, 8000, false, 10),
    CmdIntakeRetract(),
    // CmdShooterSetAngle(33),
    CmdDriveToPoint(30, 43, 50, 10000, false, 10),
    CmdDriveToPoint(0, 0, 50, 5000, true, 10),
    CmdShooterShootNote(),

    CmdShooterSetPower(0),
    CmdPrintText("Auto Blue Three Piece Right Ended"),
    CmdDriveStop()
 );
}
