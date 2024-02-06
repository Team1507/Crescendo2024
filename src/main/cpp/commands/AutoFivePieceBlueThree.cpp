
#include "commands/AutoFivePieceBlueThree.h"
#include "commands/CmdPrintText.h"
//#include "subsystems/Subway.h" <--- drivetrain
#include "commands/CmdShooterHome.h"
#include "commands/CmdShooterSetAngle.h"
#include "commands/CmdShooterSetPower.h"
#include "commands/CmdSetFeederPower.h"
#include "commands/CmdIntakeDeploy.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdShooterShootNote.h"


#include "commands/AutoFourPieceBlueThree.h"
AutoFivePieceBlueThree::AutoFivePieceBlueThree() {
  
  AddCommands(
    CmdPrintText("Auto Five Piece Blue Three Started"), 
    CmdShooterHome(),
    CmdShooterSetAngle(0),
    CmdShooterSetPower(0),
    //Rotate to speaker
    CmdShooterShootNote(0),
    //Rotate to starting position
    CmdIntakeDeploy(),
    //Drive backwards
    //Rotate to speaker
    CmdShooterShootNote(0),
    //Rotate to starting position
    //Arc to Note on right
    CmdIntakeDeploy(),
    //Rotate to speaker maybe middle spot
    CmdShooterShootNote(0),
    //Rotate to starting position
    //Arc to note on right
    CmdIntakeDeploy(),
    //Rotate to speaker
    CmdShooterShootNote(0),
    //Rotate to starting position
    //Drive Back
    //Sense Notes
    //Arc to One of remaining Note(s)
    CmdIntakeDeploy(),
    CmdIntakeRetract(),
    //drive  forwards
    CmdShooterSetAngle(0),//set to correct shoting angle not 0
    //rotate to speaker
    CmdShooterShootNote(0),
    CmdShooterSetPower(0),
    CmdPrintText("Auto Five Piece Blue Three Ended")
  );
}