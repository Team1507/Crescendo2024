#include "commands/AutoTwoPieceBlueThree.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/"
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"

AutoTwoPieceBlueThree::AutoTwoPieceBlueThree() {

  AddCommands(

    CmdPrintText("Auto Two Piece Blue Three"), 
    CmdShooterHome(),
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),
    //DriveTrain rotate 
    CmdSetFeederPower(),
    CmdShooterHome(),
    CmdIntakeDeploy(),
    //DriveTrain backbourd
    CmdIntakeRetract(),
    CmdPrintText("Auto Two Piece Blue Three Completed")


  );
}
