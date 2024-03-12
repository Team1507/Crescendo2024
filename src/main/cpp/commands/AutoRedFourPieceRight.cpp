#include "commands/AutoRedFourPieceRight.h"
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

AutoRedFourPieceRight::AutoRedFourPieceRight() 
{
  AddCommands(
    CmdPrintText("Auto Red Four Piece Right Started"),
    CmdDriveClearAll(),

    //Turn Too And Shoot Starting Note
    CmdShooterSetAngle(45),
    CmdShooterSetPower(0.8),
    CmdWaitShooterSpeed(),
    CmdDriveTurn2Angle(0.3, -40),
    CmdShooterShootNote(),

    //Go to second note
    CmdShooterSetAngle(52),
    CmdIntakeDeploy(),
    CmdDriveToPoint(0, 33, 0, 5000, false, 10),

    //Drive & Shoot Second Note 
    CmdDriveToPoint(57, 0, 0, 7000, true, 10),
    CmdShooterShootNote(),

    //Go To & Shoot Second Note
    CmdIntakeDeploy(),
    CmdDriveToPoint(57, 42, 0, 5000, false, 10),
    CmdDriveToPoint(57, 0, 0, 6000, true, 10),
    CmdShooterShootNote(),

    //Go To & Shoot Third Note
    CmdIntakeDeploy(),
    CmdDriveToPoint(112, 40, 30, 6000, false, 10),
    CmdDriveToPoint(57, 0, 0, 6000, true, 10),
    CmdShooterShootNote(),
    CmdIntakeRetract(),

    //Head to 5th piece
    CmdDriveToPoint(127, 176, 0, 10000, true, 10),
    CmdShooterSetPower(0.1),

    CmdPrintText("Auto Red Four Piece Right Done"),
    CmdShooterSetPower(0),
    CmdDriveStop()

  );
}
