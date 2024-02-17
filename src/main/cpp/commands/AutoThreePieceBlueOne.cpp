#include "commands/AutoThreePieceBlueOne.h"
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
#include "commands/CmdDriveAimAtTarget.h"
#include "Robot.h"

AutoThreePieceBlueOne::AutoThreePieceBlueOne() {

  AddCommands(

  CmdPrintText("Auto Three Piece Blue One Started"), 
  CmdShooterHome(),// <----
  CmdShooterSetAngle(0),
  CmdShooterSetPower(0),

  // rotate to speaker
  CmdDriveTurn2Angle(0.2,45),
  CmdShooterShootNote(),
  CmdIntakeDeploy(),

  // drive backwards
  CmdDriveToPoint(0,55,0,3000,true,10),

  // rotate to speaker
  CmdDriveTurn2Angle(0.2,45),
  CmdIntakeRetract(),
  CmdShooterShootNote(),
  CmdIntakeDeploy(),

  // drive backwards
  CmdDriveToPoint(7,212,0,3000,true,10),
  CmdIntakeRetract(),

  // drive forwards
  CmdDriveToPoint(0,150,0,3000,true,10),

  // rotate to speaker
  CmdDriveTurn2Angle(.2, 45),
  CmdShooterShootNote(),
  CmdShooterSetPower(0),
  CmdIntakeRetract(),
  CmdPrintText("Auto Three Piece Blue One Finished")

  );
}
