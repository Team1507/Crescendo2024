#include "commands/AutoTwoPieceRedOne.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drive train
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"

AutoTwoPieceRedOne::AutoTwoPieceRedOne() {

  AddCommands(

    CmdPrintText("Auto Two Piece Red One Started"), 
    CmdShooterHome(),
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),
    //DriveTrain rotate 
    CmdShooterShootNote(0),
    CmdShooterHome(),
    CmdIntakeDeploy(),
    //DriveTrain backward
    CmdShooterSetPower(0),
    CmdIntakeRetract(),
    CmdPrintText("Auto Two Piece Red One Completed")


  );
}