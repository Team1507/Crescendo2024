#include "commands/AutoRedThreePieceRight.h"
#include "commands/CmdPrintText.h"
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
AutoRedThreePieceRight::AutoRedThreePieceRight() 
{
 AddCommands(
    CmdPrintText("Auto Red Three Piece Right Started"),
    CmdDriveClearAll(),

    //Turn Too And Shoot Starting Note
    CmdShooterSetAngle(45),
    CmdShooterSetPower(0.8),
    CmdWaitShooterSpeed(),
    CmdDriveTurn2Angle(0.3, -40),
    CmdShooterShootNote(),
    CmdShooterSetAngle(37),
    CmdIntakeDeploy(),
    CmdDriveToPoint(0, 33, 0, 6000, false, 10),
    CmdDriveToPoint(-15, 28, -40, 4000, true, 10),
    CmdIntakeRetract(),
    CmdShooterShootNote(),

    //Moving to third piece
    CmdDriveToPoint(-115, 145, 20, 12000, false, 10),
    CmdDriveToPoint(-96, 205, 20, 9000, false, 10),
    CmdIntakeDeploy(),
    CmdDriveToPoint(-75, 257, 20, 7000, false, 10),

    // Drive Back Home
    CmdDriveToPoint(-105, 145, 0, 10000, false, 10),
    CmdIntakeRetract(),
    CmdShooterSetAngle(40),
    CmdDriveToPoint(-30, 43, -50, 12000, false, 10),
    CmdDriveToPoint(0, 0, -50, 7000, true, 10),
    CmdShooterShootNote(),

    CmdShooterSetPower(0),
    CmdPrintText("Auto Red Three Piece Right Ended"),
    CmdDriveStop()
 );
}
