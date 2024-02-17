#include "commands/AutoThreePieceBlueThree.h"
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

AutoThreePieceBlueThree::AutoThreePieceBlueThree() {

  AddCommands(

    CmdPrintText("Auto Three Piece Blue Two Started"),
    CmdShooterHome(),
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),

    // Turn Towards Speaker
    CmdDriveTurn2Angle(0.2, -45),

    CmdShooterShootNote(),
    CmdIntakeDeploy(),

    // drive backwards
    CmdDriveToPoint(0, 50, 0, 2000, true, 10),

    // turn to shot
    CmdDriveTurn2Angle(0.2,-45),

    CmdShooterShootNote(),
    CmdIntakeRetract(),

    // go to note on right
    CmdDriveToPoint(56.5, 55, 90, 2000, true, 10),

    // rotate towards speaker
    CmdDriveTurn2Angle(0.2,-45),

    CmdShooterShootNote(),
    CmdShooterSetPower(0),
    CmdIntakeRetract(),
    CmdPrintText("Auto Three Piece Blue Two Ended")

  );
}
