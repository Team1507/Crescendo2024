#include "commands/AutoJustShoot.h"
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

AutoJustShoot::AutoJustShoot() 
{
  AddCommands
  (
    CmdPrintText("Auto Just Shoot Started"),

    CmdDriveClearAll(),

    CmdShooterSetPower(.8),
    CmdShooterSetAngle(52),
    frc2::WaitCommand(5_s),
    CmdShooterShootNote(),
    CmdShooterSetPower(0),

    CmdDriveStop(),
    CmdPrintText("Auto Just Shoot Ended")
  );
}
