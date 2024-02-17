
#include "commands/AutoFourPieceRedTwo.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"

#include "frc2/command/WaitCommand.h"
#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdDriveForceSteerAngle.h"
#include "Robot.h"


AutoFourPieceRedTwo::AutoFourPieceRedTwo() {
{
  AddCommands(

    CmdPrintText("Auto Four Piece Red Two Started"), 
    CmdShooterHome(),// <----
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),
    CmdShooterShootNote(),
    CmdIntakeDeploy(),

    //DriveBackwards
    CmdDriveToPoint(0, -40, 0, 2000, true, 10),
    CmdShooterShootNote(),
    CmdIntakeDeploy(),

    //go to note on left
    CmdDriveToPoint(50, -40, 0, 2000, true, 10),
    CmdIntakeRetract(),

    //Rotate to speaker
    CmdDriveTurn2Angle(0.2, 45),
    CmdShooterShootNote(),

    //Rotate back to starting position
    CmdDriveTurn2Angle(0.2, -45),
    CmdIntakeDeploy(),

    //Drive back
    CmdDriveToPoint(69, -40, 0, 2000, true, 10),
    CmdDriveToPoint(69, 171, 0, 2000, true, 10),
    CmdIntakeRetract(),

    //Drive forwards
    CmdDriveToPoint(69, 75, 0, 2000, true, 10),
    
    //Rotate to speaker
    CmdDriveTurn2Angle(0.2, 45),
    CmdShooterSetAngle(0),
    CmdShooterShootNote(),
    CmdShooterSetPower(0),
    CmdPrintText("Auto Four Piece Red Two Ended")

  );
}
}