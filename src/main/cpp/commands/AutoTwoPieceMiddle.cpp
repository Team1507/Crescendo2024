#include "commands/AutoTwoPieceMiddle.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/"
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"

AutoTwoPieceMiddle::AutoTwoPieceMiddle() //add drivetrain
 {
  // AddCommands(FooCommand{}, BarCommand{});

  AddCommands(
    
    
    CmdPrintText("Auto Two Piece Middle"), 
    CmdShooterHome(),
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),
    CmdSetFeederPower(),
    CmdIntakeDeploy(),
    //Drive Back
    CmdSetFeederPower(),
    CmdShooterSetPower(0),
    CmdIntakeRetract(),
    CmdPrintText("Auto Two Piece Middle Completed")
  
  
  
  
  
  );
}
