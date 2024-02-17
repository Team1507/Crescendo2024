#include "commands/AutoTwoPieceMiddle.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <---- Drive train
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"
#include "commands/CmdDriveToPoint.h"

AutoTwoPieceMiddle::AutoTwoPieceMiddle() //add drivetrain
 {
  // AddCommands(FooCommand{}, BarCommand{});

  AddCommands(
    
    
    CmdPrintText("Auto Two Piece Middle Started"), 
    CmdShooterHome(),// <----
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),
    CmdShooterShootNote(),
    CmdIntakeDeploy(),

    //Drive Back
    CmdDriveToPoint(0, 60, 0, 2000, true, 10),
    CmdIntakeRetract(),
    CmdShooterShootNote(),
    CmdShooterSetPower(0), 
    CmdShooterSetPower(0),
    CmdIntakeRetract(),
    CmdPrintText("Auto Two Piece Middle Completed")
  
  
  
  
  
  );
}
