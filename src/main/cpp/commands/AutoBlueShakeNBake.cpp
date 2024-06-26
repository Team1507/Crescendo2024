#include "commands/AutoBlueShakeNBake.h"
#include "commands/CmdPrintText.h"
// #include "subsystems/Subway.h" <---- Drive train
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdWaitShooterSpeed.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveTurn2Angle.h"
#include <frc2/command/WaitCommand.h>

AutoBlueShakeNBake::AutoBlueShakeNBake()
{
  AddCommands(
      CmdDriveClearAll(),
      CmdPrintText("Shake N Bake Baby Blue"),
      frc2::WaitCommand(0.3_s),

      // Move and Shoot First Note
      CmdShooterSetPower(0.8),
      CmdShooterSetAngle(38),
      CmdDriveToPoint(0, 24, -15, 8000, false, 10),
      CmdShooterShootNote(),
      CmdDriveToPoint(0, 74, -15, 13000, false, 10),

      // Move to second note
      CmdShooterSetAngle(50),
      CmdDriveToPoint(-43, 200, 0, 13000, false, 10),
      CmdIntakeDeploy(),
      CmdDriveToPoint(-43, 249, 0, 6000, true, 10),

      // Go to shoot second note
      CmdDriveToPoint(8, 50, 0, 13000, false, 10),
      CmdDriveToPoint(0, 0, -25, 6000, true, 10),
      //CmdIntakeDeploy(),  // Intake earlier  //NO!!!!!  Will impact shoot
      CmdShooterShootNote(),
      //CmdIntakeRetract(),

      // Move and shoot third note
      CmdIntakeDeploy(),
      frc2::WaitCommand(0.2_s),
      CmdDriveToPoint(-28, 37, -20, 8000, false, 10),
      CmdDriveToPoint(19, 0, 0, 8000, true, 10),
      CmdShooterShootNote(),
      CmdIntakeRetract(),

      // Move and shoot forth note
      CmdShooterSetAngle(45),
      CmdIntakeDeploy(),
      CmdDriveToPoint(28, 37, 0, 6000, false, 10),
      CmdDriveToPoint(59, 20, 30, 8000, true, 10),   //was 56,20.  +3x
      CmdShooterShootNote(),
      CmdIntakeRetract(),
      CmdShooterSetAngle(42),

      // Move and shoot Fith note
      CmdIntakeDeploy(),
      CmdDriveToPoint(70, 35, 30, 3000, false, 10),
      CmdDriveToPoint(68, 25, 20, 4000, true, 10),  //was 65,26   +3x
      frc2::WaitCommand(0.1_s),
      CmdShooterShootNote(),

      CmdDriveStop(),
      CmdPrintText("Shaked N Baked Blue"));
}
