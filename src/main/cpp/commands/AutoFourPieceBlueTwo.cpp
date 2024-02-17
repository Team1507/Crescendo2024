
#include "commands/AutoFourPieceBlueTwo.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"

#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdDriveForceSteerAngle.h"
#include "commands/CmdDriveAimAtTarget.h"

AutoFourPieceBlueTwo::AutoFourPieceBlueTwo() {
{
  AddCommands(

    CmdPrintText("Auto Four Piece Blue Two Started"), 
    CmdShooterHome(),// <----
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),
    CmdShooterShootNote(),
    CmdShooterSetAngle(PIVOT_HOME_POS),
    CmdIntakeDeploy(),

    //DriveBackwards
    CmdDriveToPoint(0, 40, 0, 2000, true, 10),
    CmdIntakeRetract(),
    CmdShooterShootNote(),
    CmdShooterSetAngle(PIVOT_HOME_POS),
    CmdIntakeDeploy(),

    //Go to note on right
    CmdDriveToPoint(-50, 40, 0, 2000, true, 10),
    CmdDriveTurn2Angle(0.2, -45),
    CmdIntakeRetract(),

    //Rotate to speaker
    CmdDriveTurn2Angle(0.2, 45),
    CmdShooterShootNote(),

    //Drive back
    CmdDriveToPoint(-69, 40, 0, 2000, true, 10),
    CmdShooterSetAngle(PIVOT_HOME_POS),
    CmdIntakeDeploy(),
    CmdDriveToPoint(-69, -171, 0, 2000, true, 10),
    CmdIntakeRetract(),

    //Drive forwards
    CmdDriveToPoint(-69, -75, 0, 2000, true, 10),

    //Rotate to speaker
    CmdDriveTurn2Angle(0.2, -45),

    CmdShooterSetAngle(0),
    CmdShooterShootNote(),
    CmdShooterSetPower(0),
    CmdPrintText("Auto Four Piece Blue Two Ended")
    
  );
}
}