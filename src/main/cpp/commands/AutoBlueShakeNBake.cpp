#include "commands/AutoBlueShakeNBake.h"

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
AutoShakeNBakeBlue::AutoShakeNBakeBlue() 
{
 AddCommands(
  CmdPrintText("Shake N' Bake Baby Started"),
  CmdDriveClearAll(),
  CmdShooterSetPower(0.8),
  CmdDriveTurn2Angle(0.2, -20),
  CmdShooterSetAngle(50),
  CmdWaitShooterSpeed(),
  CmdShooterShootNote(),

  //You GOTTA SHAKE IT BEFORE YOU BAKE IT (Go To Second Note)
  CmdDriveToPoint(-10, 98, 0, 12000, false, 10), //Start inbetween Notes
  CmdDriveToPoint(-40, 195, 20, 10000, false, 10),  //Drive Around Stage, Get in position to pick up note
  CmdIntakeDeploy(),
  CmdDriveToPoint(0, 254, 35, 8000, true, 10),

  //Go Back To Shoot Seond Note
  CmdShooterSetAngle(36),
  CmdShooterSetPower(0.9),  
  CmdDriveToPoint(-40, 195, 20, 10000, false, 10),
  CmdDriveToPoint(-15, 37, 0, 5000, true, 10),
  // Drive Back To Grab Note
  //CmdShooterSetPower(0.9),
  //CmdShooterSetAngle(37),
  //SLINGSHOT BABY
  //CmdDriveToPoint(0, 145, 0, 8000, true, 10), //Drive Back Get Around Stage
  //CmdDriveToPoint(0, 43, 0, 6000, true, 10 ) //Drive To Shoot
  CmdDriveStop(),
  CmdShooterSetPower(0),
  CmdPrintText("Shaked N' Baked")
  
 );
}
