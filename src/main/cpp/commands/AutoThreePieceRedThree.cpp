#include "commands/AutoThreePieceRedThree.h"
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

AutoThreePieceRedThree::AutoThreePieceRedThree() {

  AddCommands(

  CmdPrintText("Auto Three Piece Red Two Started"), 
  CmdShooterHome(),// <----
  CmdShooterSetAngle(0),
  CmdShooterSetPower(0),

  // rotate to speaker
  CmdDriveTurn2Angle(0.2,45),
  CmdShooterShootNote(),
  CmdShooterSetAngle(PIVOT_HOME_POS),
  CmdIntakeDeploy(),

  // drive backwards
  CmdDriveToPoint(0,55,0,3000,true,10),
  CmdIntakeRetract(),

  // rotate to speaker
  CmdDriveTurn2Angle(0.2,45),
  CmdShooterSetAngle(0),
  CmdShooterShootNote(),
  CmdShooterSetAngle(PIVOT_HOME_POS),
  CmdIntakeDeploy(),

  // drive backwards
  CmdDriveToPoint(7,220,0,3000,true,10),
  CmdIntakeDeploy(),
  CmdDriveToPoint(7,212,0,2000,true,10),
  CmdIntakeRetract(),

  // drive forwards
  CmdDriveToPoint(0,150,0,3000,true,10),

  // rotate to speaker
  CmdDriveTurn2Angle(.2, 45),
  CmdShooterSetAngle(0),
  CmdShooterShootNote(),
  CmdShooterSetPower(0),
  CmdIntakeRetract(),
  CmdDriveStop(),
  CmdPrintText("Auto Three Piece Red Two Finished")

  );
}
